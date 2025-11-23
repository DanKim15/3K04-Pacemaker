# serial_com.py
from __future__ import annotations

from typing import Any, Dict, Optional
import threading

try:
    import serial  # pyserial
except ImportError:  # failure if pyserial is missing
    serial = None  # type: ignore


SYNC_BYTE = 0x16
MSG_TYPE_SET_PARAMS = 0x01
MSG_TYPE_ECHO_REQ = 0x02
MSG_TYPE_EGRAM_REQ = 0x03
MSG_TYPE_EGRAM_DATA = 0x04
MSG_TYPE_EGRAM_STOP = 0x05


class SerialManager:
    """
    Handles UART communication with the pacemaker.

    - 115200 8-N-1
    - 20-byte packets
    - Background thread to read echo packets and push decoded params into App.
    """

    def __init__(self, app, port: Optional[str] = None, baudrate: int = 115200):
        self.app = app
        self.baudrate = baudrate
        self.ser: Optional[serial.Serial] = None  # type: ignore[assignment]
        self.port_name: str = port or self._default_port_from_store()
        self._stop_event = threading.Event()
        self._read_thread: Optional[threading.Thread] = None
        self._egram_streaming = False

    @property
    def is_open(self) -> bool:
        return bool(self.ser and self.ser.is_open)

    def open_port(self, port: Optional[str] = None) -> tuple[bool, Optional[str]]:
        """Open the serial port and start the read thread."""
        if serial is None:
            return False, "pyserial is not installed. Please install 'pyserial'."

        if self.is_open:
            return True, None

        if port is not None:
            self.port_name = port

        try:
            self.ser = serial.Serial(  # type: ignore[call-arg]
                port=self.port_name,
                baudrate=self.baudrate,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=0.1,
                write_timeout=0.1,
            )
        except Exception as e:
            self.ser = None
            return False, f"Failed to open port {self.port_name}: {e}"

        # Start background reader
        self._stop_event.clear()
        self._read_thread = threading.Thread(target=self._read_loop, daemon=True)
        self._read_thread.start()
        return True, None

    def close_port(self) -> None:
        """Stop read thread and close serial port."""
        self._stop_event.set()
        if self._read_thread and self._read_thread.is_alive():
            self._read_thread.join(timeout=0.5)

        if self.ser:
            try:
                self.ser.close()
            except Exception:
                pass
        self.ser = None

    def send_packet(self, packet: bytes) -> bool:
        """Low-level: send a raw 20-byte packet."""
        if not self.is_open or not self.ser:
            return False
        if len(packet) != 20:
            raise ValueError("Packet must be exactly 20 bytes")

        try:
            self.ser.write(packet)
            self.ser.flush()
            return True
        except Exception:
            # On any serious error, mark comms down
            try:
                self.app.after(0, setattr, self.app, "device_com", False)
            except Exception:
                pass
            return False

    def send_set_parameters(self, params: Dict[str, Any]) -> bool:
        """Encode current parameters into the 20-byte Set Parameters packet and send."""
        packet = self._encode_params(params)
        print("SET packet:", [f"0x{b:02X}" for b in packet])
        return self.send_packet(packet)

    def request_echo(self) -> bool:
        """
        Send an Echo Request (msg_type 0x02).
        Pacemaker will respond with a 20-byte echo packet.
        """
        buf = bytearray(20)
        buf[0] = SYNC_BYTE
        buf[1] = MSG_TYPE_ECHO_REQ
        # bytes 2-19 can be zero
        return self.send_packet(bytes(buf))
    
    def request_egram(self, channel: str = "Both") -> bool:
        """
        Send an Egram Request (msg_type 0x03).
        Channel: "Atrial", "Ventricular", or "Both"
        """
        buf = bytearray(20)
        buf[0] = SYNC_BYTE
        buf[1] = MSG_TYPE_EGRAM_REQ
        
        # Channel selection: 0=Both, 1=Atrial, 2=Ventricular
        if channel == "Atrial":
            buf[2] = 1
        elif channel == "Ventricular":
            buf[2] = 2
        else:  # Both
            buf[2] = 0
        
        # bytes 3-19 can be zero
        self._egram_streaming = True
        return self.send_packet(bytes(buf))
    
    def stop_egram(self) -> bool:
        """
        Send an Egram Stop request (msg_type 0x05).
        """
        buf = bytearray(20)
        buf[0] = SYNC_BYTE
        buf[1] = MSG_TYPE_EGRAM_STOP
        # bytes 2-19 can be zero
        self._egram_streaming = False
        return self.send_packet(bytes(buf))
    
    def _default_port_from_store(self) -> str:
        """
        Try to read a default port from the store JSON, e.g.:
        "serial": { "port": "COM4" }
        """
        try:
            data = getattr(self.app.store, "data", {})
            serial_cfg = data.get("serial", {})
            return serial_cfg.get("port", "COM4")
        except Exception:
            return "COM4"

    def _read_loop(self) -> None:
        """Background thread: read 20-byte echo packets."""
        if not self.ser:
            return

        while not self._stop_event.is_set():
            try:
                data = self.ser.read(20)
            except Exception:
                # Serial port broke; mark disconnected and exit
                try:
                    self.app.after(0, setattr, self.app, "device_com", False)
                except Exception:
                    pass
                break

            if not data:
                continue
            if len(data) != 20:
                # Not a full packet, skip
                continue
            if data[0] != SYNC_BYTE:
                # Not our packet
                continue

            decoded = self._decode_echo_packet(data)
            if decoded is None:
                # Check if it's an egram data packet instead
                if len(data) >= 2 and data[1] == MSG_TYPE_EGRAM_DATA:
                    egram_data = self._decode_egram_packet(data)
                    if egram_data is not None:
                        try:
                            self.app.after(0, self.app.update_egram_data, egram_data)
                        except Exception:
                            pass
                continue

            # Push into Tk main thread
            try:
                self.app.after(0, self.app.update_params_from_device, decoded)
            except Exception:
                # If app vanished, just stop
                break

    def _encode_params(self, params: Dict[str, Any]) -> bytes:
        """
        Map app.current_params -> 20-byte Set Parameters packet.

        Layout:
          0: SYNC (0x16)
          1: MSG TYPE (0x01)
          2: MODE_SELECT (0..7)
          3: HYSTERESIS (0/1)
          4-5: LRL (uint16, bpm, big-endian)
          6-7: URL (uint16, bpm, big-endian)
          8-9:  Atrial amplitude register (uint16, big-endian)
         10-11: Ventricular amplitude register (uint16, big-endian)
         12-13: Atrial pulse width (ms, uint16, big-endian)
         14-15: Ventricular pulse width (ms, uint16, big-endian)
         16-17: ARP (ms, uint16, big-endian)
         18-19: VRP (ms, uint16, big-endian)
        """
        buf = bytearray(20)
        buf[0] = SYNC_BYTE
        buf[1] = MSG_TYPE_SET_PARAMS

        # Mode + hysteresis
        mode_str = str(params.get("Mode", "AOO")).upper()
        mode_code = self.app.mode_to_code(mode_str)
        hyst_bool = bool(params.get("Hysteresis", False))
        buf[2] = mode_code & 0xFF
        buf[3] = 1 if hyst_bool else 0

        # Replace the helper in _encode_params with little-endian:
        def put_u16_le(idx: int, value: int) -> None:
            value = int(value) & 0xFFFF
            buf[idx] = value & 0xFF          # low byte first
            buf[idx + 1] = (value >> 8) & 0xFF

        # Rates
        LRL = int(params.get("LRL", 60))
        URL = int(params.get("URL", 120))
        put_u16_le(4, LRL)
        put_u16_le(6, URL)

        # Amplitude: volts -> register (x10), clamp to [1..50]
        atr_amp_v = int(params.get("AtrialAmplitude", 3.5))
        vent_amp_v = int(params.get("VentricularAmplitude", 3.5))
        atr_reg = max(1, min(7, int(atr_amp_v)))
        vent_reg = max(1, min(7, int(vent_amp_v)))
        put_u16_le(8, atr_reg)
        put_u16_le(10, vent_reg)

        # Pulse widths: float ms -> int ms, clamp [1..30]
        atr_pw = max(10, min(3000, int(round(float(params.get("AtrialPulseWidth", 40))))))
        vent_pw = max(10, min(3000, int(round(float(params.get("VentricularPulseWidth", 40))))))
        put_u16_le(12, atr_pw)
        put_u16_le(14, vent_pw)

        # Refractory periods: ARP/VRP
        arp = int(params.get("ARP", 250))
        vrp = int(params.get("VRP", 320))
        put_u16_le(16, arp)
        put_u16_le(18, vrp)

        return bytes(buf)

    def _decode_echo_packet(self, data: bytes) -> Optional[Dict[str, Any]]:
        """
        Decode a 20-byte echo packet into a params dict suitable for app.current_params.
        data[0] already checked == SYNC_BYTE.
        """
        if len(data) != 20:
            return None

        def get_u16_le(idx: int) -> int:
            return data[idx] | (data[idx + 1] << 8)

        mode_code = data[2]
        hysteresis_flag = data[3]

        LRL = get_u16_le(4)
        URL = get_u16_le(6)

        atr_reg = get_u16_le(8)
        vent_reg = get_u16_le(10)
        atr_pw_ms = get_u16_le(12)
        vent_pw_ms = get_u16_le(14)
        arp = get_u16_le(16)
        vrp = get_u16_le(18)

        params: Dict[str, Any] = {
            "Mode": self.app.code_to_mode(mode_code),
            "Hysteresis": bool(hysteresis_flag),
            "LRL": LRL,
            "URL": URL,
            "AtrialAmplitude": atr_reg / 20.0,
            "VentricularAmplitude": vent_reg / 20.0,
            "AtrialPulseWidth": float(atr_pw_ms),
            "VentricularPulseWidth": float(vent_pw_ms),
            "ARP": arp,
            "VRP": vrp,
        }
        return params
    
    def _decode_egram_packet(self, data: bytes) -> Optional[Dict[str, Any]]:
        """
        Decode a 20-byte egram data packet.
        
        Packet format (20 bytes):
          0: SYNC (0x16)
          1: MSG TYPE (0x04)
          2: Channel flags (bit 0=atrial valid, bit 1=ventricular valid)
          3: Event marker type (0=none, 1-15=marker codes)
          4-5: Timestamp (uint16, ms, little-endian)
          6-7: Atrial sample (int16, mV, little-endian)
          8-9: Ventricular sample (int16, mV, little-endian)
          10-11: Event marker timestamp offset (uint16, ms from packet timestamp, little-endian)
          12-13: Reserved
          14-19: Reserved
        """
        if len(data) != 20 or data[0] != SYNC_BYTE or data[1] != MSG_TYPE_EGRAM_DATA:
            return None
        
        def get_u16_le(idx: int) -> int:
            return data[idx] | (data[idx + 1] << 8)
        
        def get_i16_le(idx: int) -> int:
            val = get_u16_le(idx)
            if val >= 0x8000:
                val -= 0x10000
            return val
        
        channel_flags = data[2]
        event_marker = data[3]
        timestamp_ms = get_u16_le(4)
        atrial_sample = get_i16_le(6)  # mV
        ventricular_sample = get_i16_le(8)  # mV
        event_offset_ms = get_u16_le(10)
        
        # Marker type mapping
        marker_types = {
            0: None,
            1: 'AS', 2: 'AP', 3: 'AT',
            4: 'VS', 5: 'VP', 6: 'PVC',
            7: 'TN', 8: 'REF',
            9: 'UP', 10: 'DOWN',
            11: 'SR', 12: 'HY',
            13: 'ATR-Dur', 14: 'ATR-FB', 15: 'ATR-End',
            16: 'PVP',
        }
        
        marker_type = marker_types.get(event_marker)
        
        # Determine which channels are valid
        atrial_valid = bool(channel_flags & 0x01)
        ventricular_valid = bool(channel_flags & 0x02)
        
        # Calculate absolute timestamp (assuming pacemaker sends relative timestamps)
        # For now, use system time as base
        import time
        base_time = time.time() * 1000  # ms
        
        result: Dict[str, Any] = {
            "timestamp_ms": base_time + timestamp_ms,
            "atrial_value": float(atrial_sample) if atrial_valid else None,
            "ventricular_value": float(ventricular_sample) if ventricular_valid else None,
            "event_marker": marker_type,
            "event_channel": "Atrial" if event_marker in [1, 2, 3] else ("Ventricular" if event_marker in [4, 5, 6] else None),
            "event_timestamp_ms": base_time + timestamp_ms + event_offset_ms if event_marker > 0 else None,
        }
        
        return result
