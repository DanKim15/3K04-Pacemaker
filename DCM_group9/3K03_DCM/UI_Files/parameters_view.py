from __future__ import annotations
import tkinter as tk
from tkinter import ttk, messagebox


class ParametersView(ttk.Frame):
    RANGES = {
        "LRL": "[30-175 ppm]",
        "URL": "(> LRL) [up to 220 ppm]",
        "AtrialAmplitude": "[0.5-7.0 V]",
        "AtrialPulseWidth": "[10-3000 ms]",
        "VentricularAmplitude": "[0.5-7.0 V]",
        "VentricularPulseWidth": "[10-3000 ms]",
        "ARP": "[100-500 ms]",
        "VRP": "[100-500 ms]",
    }

    def __init__(self, parent, app):
        super().__init__(parent, padding=12)
        self.app = app
        self.param_vars: dict[str, tk.StringVar] = {}
        # Mode is primarily controlled via ModesView, but we keep a local copy for validation
        self.mode_var = tk.StringVar(value=self.app.current_params.get("Mode", "AOO"))
        self.hysteresis_var = tk.BooleanVar(
            value=bool(self.app.current_params.get("Hysteresis", False))
        )
        self._build()

    # -------------------------------------------------------------------------
    # UI construction
    # -------------------------------------------------------------------------
    def _build(self):
        grid = ttk.Frame(self)
        grid.pack(fill=tk.X)

        fields = [
            ("LRL (ppm)", "LRL"),
            ("URL (ppm)", "URL"),
            ("Atrial Amplitude (V)", "AtrialAmplitude"),
            ("Atrial Pulse Width (ms)", "AtrialPulseWidth"),
            ("Ventricular Amplitude (V)", "VentricularAmplitude"),
            ("Ventricular Pulse Width (ms)", "VentricularPulseWidth"),
            ("ARP (ms)", "ARP"),
            ("VRP (ms)", "VRP"),
        ]

        for r, (label, key) in enumerate(fields):
            row = ttk.Frame(grid)
            row.grid(row=r, column=0, sticky="w", pady=4)

            ttk.Label(row, text=f"{label}").pack(side=tk.LEFT)

            ttk.Label(
                row,
                text=f"  {self.RANGES[key]}",
                foreground="#666",
            ).pack(side=tk.LEFT)

            var = tk.StringVar()
            self.param_vars[key] = var
            ttk.Entry(row, textvariable=var, width=16).pack(side=tk.LEFT, padx=(10, 0))

        # Hysteresis checkbox
        hyst_row = ttk.Frame(self)
        hyst_row.pack(anchor="w", pady=(10, 0))
        ttk.Checkbutton(
            hyst_row,
            text="Hysteresis enabled",
            variable=self.hysteresis_var,
        ).pack(side=tk.LEFT)

        # Buttons row
        btns = ttk.Frame(self)
        btns.pack(anchor="w", pady=(12, 0))

        ttk.Button(
            btns,
            text="Apply Changes",
            command=self._apply_params,
        ).grid(row=0, column=0, padx=(0, 6))

        ttk.Button(
            btns,
            text="Reset to Defaults",
            command=self._reset_params,
        ).grid(row=0, column=1, padx=(0, 6))

        ttk.Button(
            btns,
            text="Read From Device",
            command=self._read_from_device,
        ).grid(row=0, column=2)

    # -------------------------------------------------------------------------
    # Lifecycle hooks
    # -------------------------------------------------------------------------
    def on_session_start(self):
        self._refresh_params_ui()

    def _refresh_params_ui(self):
        # Update entry boxes from app.current_params
        for k, var in self.param_vars.items():
            var.set(str(self.app.current_params.get(k)))
        # Update Hysteresis checkbox
        self.hysteresis_var.set(bool(self.app.current_params.get("Hysteresis", False)))
        # Keep mode in sync (even though Mode is edited in ModesView)
        self.mode_var.set(self.app.current_params.get("Mode", "AOO"))

    # -------------------------------------------------------------------------
    # Actions
    # -------------------------------------------------------------------------
    def _apply_params(self):
        # Start from current app params, then overwrite with entry values
        candidate = dict(self.app.current_params)
        for k, var in self.param_vars.items():
            candidate[k] = var.get()

        # Keep current mode from the app
        candidate["Mode"] = self.app.current_params.get("Mode", "AOO")
        # Hysteresis from checkbox
        candidate["Hysteresis"] = self.hysteresis_var.get()

        # Validate (using local proxy to avoid circular import)
        ok, msg = ValidatorProxy.validate(candidate)
        if not ok:
            messagebox.showerror("Invalid parameters", msg)
            return

        # Cast to proper types and persist
        candidate["LRL"] = int(candidate["LRL"])
        candidate["URL"] = int(candidate["URL"])
        candidate["AtrialAmplitude"] = int(candidate["AtrialAmplitude"])
        candidate["AtrialPulseWidth"] = int(candidate["AtrialPulseWidth"])
        candidate["VentricularAmplitude"] = int(candidate["VentricularAmplitude"])
        candidate["VentricularPulseWidth"] = int(candidate["VentricularPulseWidth"])
        candidate["ARP"] = int(candidate["ARP"])
        candidate["VRP"] = int(candidate["VRP"])
        candidate["Hysteresis"] = bool(candidate.get("Hysteresis", False))

        # Update app state
        self.app.current_params.update(candidate)

        # Save as __last__ for the current user
        if self.app.active_user:
            self.app.store.save_profile(
                self.app.active_user,
                "__last__",
                self.app.current_params,
            )

        # If device is connected, also send Set Parameters packet over UART
        if (
            getattr(self.app, "serial_manager", None)
            and self.app.device_com
            and self.app.serial_manager.is_open
        ):
            try:
                sent = self.app.serial_manager.send_set_parameters(
                    self.app.current_params
                )
                if not sent:
                    messagebox.showwarning(
                        "Programming Failed",
                        "Parameters saved locally, but failed to send to device.",
                    )
                else:
                    messagebox.showinfo(
                        "Saved",
                        "Parameters updated, saved, and sent to device.",
                    )
            except Exception as e:
                messagebox.showerror(
                    "UART Error",
                    f"Parameters saved locally, but failed to send to device:\n{e}",
                )
        else:
            messagebox.showinfo(
                "Saved",
                "Parameters updated and saved as last-used for this user.\n"
                "No device connection; nothing sent over UART.",
            )

    def _reset_params(self):
        # Reset to app's default parameters
        from app import Parameters  # local import to avoid circular at import time

        self.app.current_params = Parameters.default_dict()
        # Keep mode in sync with defaults
        self.mode_var.set(self.app.current_params.get("Mode", "AOO"))
        self.hysteresis_var.set(bool(self.app.current_params.get("Hysteresis", False)))
        self._refresh_params_ui()

    def _read_from_device(self):
        """
        Send an echo request and let SerialManager update the UI asynchronously
        when the echo packet is received.
        """
        if (
            not getattr(self.app, "serial_manager", None)
            or not self.app.device_com
            or not self.app.serial_manager.is_open
        ):
            messagebox.showwarning(
                "No Device",
                "Device is not connected. Connect the device first.",
            )
            return

        try:
            ok = self.app.serial_manager.request_echo()
        except Exception as e:
            messagebox.showerror(
                "UART Error",
                f"Failed to send echo request:\n{e}",
            )
            return

        if not ok:
            messagebox.showwarning(
                "Echo Request Failed",
                "Echo request could not be sent to the device.",
            )
        else:
            # Echo handling is via SerialManager.read_loop -> App.update_params_from_device
            messagebox.showinfo(
                "Echo Requested",
                "Echo request sent. Parameters will update when the device responds.",
            )


# -------------------------------------------------------------------------
# Fallback validator when imported standalone
# -------------------------------------------------------------------------
class ValidatorProxy:
    @staticmethod
    def validate(params: dict[str, str]):
        """
        Mirror of app.Validator.validate, but defined locally to avoid circular import.
        """
        try:
            LRL = int(params["LRL"])
            URL = int(params["URL"])
            AA = int(params["AtrialAmplitude"])
            APW = int(params["AtrialPulseWidth"])
            VA = int(params["VentricularAmplitude"])
            VPW = int(params["VentricularPulseWidth"])
            ARP = int(params["ARP"])
            VRP = int(params["VRP"])
            Mode = str(params["Mode"]).upper()
            _ = bool(params.get("Hysteresis", False))
        except Exception as e:
            return False, f"Invalid input type: {e}"

        if not (30 <= LRL <= 175):
            return False, "LRL should be between 30 and 175 ppm."
        if not (LRL < URL <= 220):
            return False, "URL must be > LRL and ≤ 220 ppm."
        if not (1 <= AA <= 7):
            return False, "Atrial Amplitude should be 0.5-7.0 V."
        if not (1 <= VA <= 7):
            return False, "Ventricular Amplitude should be 0.5-7.0 V."
        if not (10 <= APW <= 3000):
            return False, "Atrial Pulse Width should be 10-3000 ms."
        if not (10 <= VPW <= 3000):
            return False, "Ventricular Pulse Width should be 10-3000 ms."
        if not (100 <= ARP <= 500):
            return False, "ARP should be 100-500 ms."
        if not (100 <= VRP <= 500):
            return False, "VRP should be 100-500 ms."

        valid_modes = {
            "AOO",
            "VOO",
            "AAI",
            "VVI",
            "AOO-R",
            "VOO-R",
            "AAI-R",
            "VVI-R",
        }
        if Mode not in valid_modes:
            return (
                False,
                "Mode must be one of: AOO, VOO, AAI, VVI, AOO-R, VOO-R, AAI-R, VVI-R.",
            )

        return True, "OK"
