from __future__ import annotations
import tkinter as tk
from tkinter import ttk, messagebox
from typing import Optional, List, Tuple, Dict, Any
import collections
import time

try:
    import matplotlib
    matplotlib.use('TkAgg')
    from matplotlib.figure import Figure
    from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
    from matplotlib.animation import FuncAnimation
    import numpy as np
    MATPLOTLIB_AVAILABLE = True
except ImportError:
    MATPLOTLIB_AVAILABLE = False


# Event marker definitions
EVENT_MARKERS = {
    'AS': ('Atrial Sensed', 'blue', '^'),
    'AP': ('Atrial Paced', 'red', 'v'),
    'AT': ('A-Tachy Sense', 'orange', 's'),
    'VS': ('Ventricular Sensed', 'green', '^'),
    'VP': ('Ventricular Paced', 'purple', 'v'),
    'PVC': ('Premature Ventricular Contraction', 'brown', 'x'),
    'TN': ('Noise Indication', 'black', '*'),
    'REF': ('During Refractory', 'gray', 'o'),
    'UP': ('Rate Smoothing Up', 'cyan', '+'),
    'DOWN': ('Rate Smoothing Down', 'magenta', '+'),
    'SR': ('Motion Sensor Rate', 'yellow', 'D'),
    'HY': ('Hysteresis Rate Pace', 'pink', 'D'),
    'ATR-Dur': ('ATR Onset Started', 'darkorange', 's'),
    'ATR-FB': ('ATR Fallback Started', 'darkred', 's'),
    'ATR-End': ('ATR Fallback Ended', 'darkgreen', 's'),
    'PVP': ('PVARP Extension', 'darkblue', '>'),
}


class EgramView(ttk.Frame):
    """
    Real-time electrogram display with event markers.
    Supports atrial, ventricular, or both channels.
    """
    
    def __init__(self, parent, app):
        super().__init__(parent, padding=12)
        self.app = app
        
        # Data buffers (circular buffers for real-time display)
        self.max_points = 2000  # Number of samples to display
        self.sample_rate = 1000  # Hz (1 ms per sample)
        
        # Circular buffers for egram data
        self.atrial_data = collections.deque(maxlen=self.max_points)
        self.ventricular_data = collections.deque(maxlen=self.max_points)
        self.time_data = collections.deque(maxlen=self.max_points)
        
        # Event markers: list of (time_ms, channel, marker_type, description)
        self.event_markers: List[Tuple[float, str, str, str]] = []
        self.marker_time_window = 5000  # Show markers from last 5 seconds
        
        # State
        self.is_streaming = False
        self.channel_selection = "Both"  # "Atrial", "Ventricular", "Both"
        self.gain = 1.0  # 0.5, 1.0, or 2.0
        
        # Track markers and annotations for cleanup (per axis)
        self.marker_artists_atrial: List = []
        self.annotation_artists_atrial: List = []
        self.marker_artists_ventricular: List = []
        self.annotation_artists_ventricular: List = []
        
        # UI variables
        self.channel_var = tk.StringVar(value="Both")
        self.gain_var = tk.StringVar(value="1X")
        
        if not MATPLOTLIB_AVAILABLE:
            self._build_no_matplotlib()
        else:
            self._build()
    
    def _build_no_matplotlib(self):
        """Build UI when matplotlib is not available."""
        ttk.Label(
            self,
            text="Egram Display",
            font=("Segoe UI", 12, "bold")
        ).pack(anchor="w", pady=(0, 12))
        
        error_frame = ttk.Frame(self, style="Card.TFrame", padding=20)
        error_frame.pack(fill=tk.BOTH, expand=True)
        
        ttk.Label(
            error_frame,
            text="Matplotlib is required for egram display.",
            font=("Segoe UI", 11),
            foreground="red"
        ).pack()
        
        ttk.Label(
            error_frame,
            text="Please install matplotlib: pip install matplotlib",
            font=("Segoe UI", 10),
            foreground="#666"
        ).pack(pady=(8, 0))
    
    def _build(self):
        """Build the egram display UI."""
        # Control panel
        control_frame = ttk.Frame(self)
        control_frame.pack(fill=tk.X, pady=(0, 12))
        
        # Channel selection
        ttk.Label(control_frame, text="Channel:", font=("Segoe UI", 10)).grid(row=0, column=0, padx=(0, 8), sticky="w")
        channel_combo = ttk.Combobox(
            control_frame,
            textvariable=self.channel_var,
            values=["Atrial", "Ventricular", "Both"],
            state="readonly",
            width=12
        )
        channel_combo.grid(row=0, column=1, padx=(0, 20))
        channel_combo.bind("<<ComboboxSelected>>", self._on_channel_change)
        
        # Gain selection
        ttk.Label(control_frame, text="Gain:", font=("Segoe UI", 10)).grid(row=0, column=2, padx=(0, 8), sticky="w")
        gain_combo = ttk.Combobox(
            control_frame,
            textvariable=self.gain_var,
            values=["0.5X", "1X", "2X"],
            state="readonly",
            width=8
        )
        gain_combo.grid(row=0, column=3, padx=(0, 20))
        gain_combo.bind("<<ComboboxSelected>>", self._on_gain_change)
        
        # Control buttons
        self.start_btn = ttk.Button(
            control_frame,
            text="Start Egram",
            command=self._start_egram
        )
        self.start_btn.grid(row=0, column=4, padx=(0, 8))
        
        self.stop_btn = ttk.Button(
            control_frame,
            text="Stop Egram",
            command=self._stop_egram,
            state="disabled"
        )
        self.stop_btn.grid(row=0, column=5, padx=(0, 8))
        
        ttk.Button(
            control_frame,
            text="Clear Display",
            command=self._clear_display
        ).grid(row=0, column=6)
        
        # Matplotlib figure and canvas
        self.fig = Figure(figsize=(10, 6), dpi=100)
        self.canvas = FigureCanvasTkAgg(self.fig, self)
        self.canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
        
        # Create subplots based on channel selection
        self._setup_plots()
        
        # Animation for real-time updates
        self.animation: Optional[FuncAnimation] = None
        
        # Initialize data with zeros
        self._initialize_data()
    
    def _setup_plots(self):
        """Setup matplotlib plots based on channel selection."""
        self.fig.clear()
        
        if self.channel_selection == "Both":
            self.ax_atrial = self.fig.add_subplot(2, 1, 1)
            self.ax_ventricular = self.fig.add_subplot(2, 1, 2)
            self.ax_atrial.set_title("Atrial Electrogram", fontsize=10, fontweight='bold')
            self.ax_ventricular.set_title("Ventricular Electrogram", fontsize=10, fontweight='bold')
            self.ax_ventricular.set_xlabel("Time (ms)", fontsize=9)
            self.ax_atrial.set_ylabel("Amplitude (mV)", fontsize=9)
            self.ax_ventricular.set_ylabel("Amplitude (mV)", fontsize=9)
            self.ax_atrial.grid(True, alpha=0.3)
            self.ax_ventricular.grid(True, alpha=0.3)
            self.line_atrial = None
            self.line_ventricular = None
        elif self.channel_selection == "Atrial":
            self.ax_atrial = self.fig.add_subplot(1, 1, 1)
            self.ax_ventricular = None
            self.ax_atrial.set_title("Atrial Electrogram", fontsize=12, fontweight='bold')
            self.ax_atrial.set_xlabel("Time (ms)", fontsize=10)
            self.ax_atrial.set_ylabel("Amplitude (mV)", fontsize=10)
            self.ax_atrial.grid(True, alpha=0.3)
            self.line_atrial = None
            self.line_ventricular = None
        else:  # Ventricular
            self.ax_ventricular = self.fig.add_subplot(1, 1, 1)
            self.ax_atrial = None
            self.ax_ventricular.set_title("Ventricular Electrogram", fontsize=12, fontweight='bold')
            self.ax_ventricular.set_xlabel("Time (ms)", fontsize=10)
            self.ax_ventricular.set_ylabel("Amplitude (mV)", fontsize=10)
            self.ax_ventricular.grid(True, alpha=0.3)
            self.line_atrial = None
            self.line_ventricular = None
        
        self.fig.tight_layout()
        self.canvas.draw()
    
    def _initialize_data(self):
        """Initialize data buffers with zeros."""
        current_time = time.time() * 1000  # ms
        for i in range(self.max_points):
            t = current_time - (self.max_points - i) * (1000.0 / self.sample_rate)
            self.time_data.append(t)
            self.atrial_data.append(0.0)
            self.ventricular_data.append(0.0)
    
    def _on_channel_change(self, event=None):
        """Handle channel selection change."""
        self.channel_selection = self.channel_var.get()
        self._setup_plots()
        if self.is_streaming:
            self._start_animation()
    
    def _on_gain_change(self, event=None):
        """Handle gain selection change."""
        gain_str = self.gain_var.get()
        if gain_str == "0.5X":
            self.gain = 0.5
        elif gain_str == "1X":
            self.gain = 1.0
        else:  # "2X"
            self.gain = 2.0
        # Gain change will be applied in the update function
    
    def _start_egram(self):
        """Start egram streaming."""
        if not self.app.device_com or not self.app.serial_manager.is_open:
            messagebox.showwarning(
                "No Device",
                "Device is not connected. Connect the device first."
            )
            return

        # Request egram data from device
        success = self.app.serial_manager.request_egram(
            channel=self.channel_selection
        )

        if not success:
            messagebox.showerror(
                "Request Failed",
                "Failed to send egram request to device."
            )
            return

        self.is_streaming = True
        self.start_btn.config(state="disabled")
        self.stop_btn.config(state="normal")

        # Start animation
        self._start_animation()
    
    def _stop_egram(self):
        """Stop egram streaming."""
        self.is_streaming = False
        self.start_btn.config(state="normal")
        self.stop_btn.config(state="disabled")
        
        if self.animation:
            self.animation.event_source.stop()
            self.animation = None
        
        # Send stop request to device
        if self.app.device_com and self.app.serial_manager.is_open:
            self.app.serial_manager.stop_egram()
    
    def _clear_display(self):
        """Clear the display and reset buffers."""
        self._initialize_data()
        self.event_markers.clear()
        if self.animation:
            self._update_plot()
    
    def _start_animation(self):
        """Start the matplotlib animation."""
        if self.animation:
            self.animation.event_source.stop()
        
        # Update at ~30 FPS for smooth display
        interval = 1000 / 30  # ms
        self.animation = FuncAnimation(
            self.fig,
            self._update_plot,
            interval=interval,
            blit=False
        )
        self.canvas.draw()
    
    def _update_plot(self, frame=None):
        """Update the plot with current data."""
        if not MATPLOTLIB_AVAILABLE:
            return
        
        # Convert deques to numpy arrays
        time_arr = np.array(self.time_data)
        atrial_arr = np.array(self.atrial_data) * self.gain
        ventricular_arr = np.array(self.ventricular_data) * self.gain
        
        # Update plots based on channel selection
        if self.channel_selection == "Both":
            if self.line_atrial is None:
                self.line_atrial, = self.ax_atrial.plot([], [], 'b-', linewidth=0.8, label='Atrial')
                self.ax_atrial.legend(loc='upper right', fontsize=8)
            if self.line_ventricular is None:
                self.line_ventricular, = self.ax_ventricular.plot([], [], 'g-', linewidth=0.8, label='Ventricular')
                self.ax_ventricular.legend(loc='upper right', fontsize=8)
            
            self.line_atrial.set_data(time_arr, atrial_arr)
            self.line_ventricular.set_data(time_arr, ventricular_arr)
            
            # Set axis limits (show last 5 seconds)
            if len(time_arr) > 0:
                time_min = max(time_arr[-1] - 5000, time_arr[0])
                time_max = time_arr[-1] + 100
                self.ax_atrial.set_xlim(time_min, time_max)
                self.ax_ventricular.set_xlim(time_min, time_max)
                
                # Auto-scale Y axis
                if len(atrial_arr) > 0:
                    atrial_min, atrial_max = np.min(atrial_arr), np.max(atrial_arr)
                    margin = (atrial_max - atrial_min) * 0.1 if atrial_max != atrial_min else 1.0
                    self.ax_atrial.set_ylim(atrial_min - margin, atrial_max + margin)
                
                if len(ventricular_arr) > 0:
                    vent_min, vent_max = np.min(ventricular_arr), np.max(ventricular_arr)
                    margin = (vent_max - vent_min) * 0.1 if vent_max != vent_min else 1.0
                    self.ax_ventricular.set_ylim(vent_min - margin, vent_max + margin)
            
            # Draw event markers
            self._draw_markers(self.ax_atrial, "Atrial")
            self._draw_markers(self.ax_ventricular, "Ventricular")
            
        elif self.channel_selection == "Atrial":
            if self.line_atrial is None:
                self.line_atrial, = self.ax_atrial.plot([], [], 'b-', linewidth=0.8, label='Atrial')
                self.ax_atrial.legend(loc='upper right', fontsize=10)
            
            self.line_atrial.set_data(time_arr, atrial_arr)
            
            if len(time_arr) > 0:
                time_min = max(time_arr[-1] - 5000, time_arr[0])
                time_max = time_arr[-1] + 100
                self.ax_atrial.set_xlim(time_min, time_max)
                
                if len(atrial_arr) > 0:
                    atrial_min, atrial_max = np.min(atrial_arr), np.max(atrial_arr)
                    margin = (atrial_max - atrial_min) * 0.1 if atrial_max != atrial_min else 1.0
                    self.ax_atrial.set_ylim(atrial_min - margin, atrial_max + margin)
            
            self._draw_markers(self.ax_atrial, "Atrial")
            
        else:  # Ventricular
            if self.line_ventricular is None:
                self.line_ventricular, = self.ax_ventricular.plot([], [], 'g-', linewidth=0.8, label='Ventricular')
                self.ax_ventricular.legend(loc='upper right', fontsize=10)
            
            self.line_ventricular.set_data(time_arr, ventricular_arr)
            
            if len(time_arr) > 0:
                time_min = max(time_arr[-1] - 5000, time_arr[0])
                time_max = time_arr[-1] + 100
                self.ax_ventricular.set_xlim(time_min, time_max)
                
                if len(ventricular_arr) > 0:
                    vent_min, vent_max = np.min(ventricular_arr), np.max(ventricular_arr)
                    margin = (vent_max - vent_min) * 0.1 if vent_max != vent_min else 1.0
                    self.ax_ventricular.set_ylim(vent_min - margin, vent_max + margin)
            
            self._draw_markers(self.ax_ventricular, "Ventricular")
        
        self.fig.canvas.draw_idle()
    
    def _draw_markers(self, ax, channel: str):
        """Draw event markers on the plot."""
        # Clear existing markers and annotations for this channel
        if channel == "Atrial":
            artists = self.marker_artists_atrial
            annotations = self.annotation_artists_atrial
        else:  # Ventricular
            artists = self.marker_artists_ventricular
            annotations = self.annotation_artists_ventricular
        
        for artist in artists:
            try:
                artist.remove()
            except:
                pass
        for artist in annotations:
            try:
                artist.remove()
            except:
                pass
        artists.clear()
        annotations.clear()
        
        # Get current time window
        if len(self.time_data) == 0:
            return
        
        current_time = self.time_data[-1]
        time_min = current_time - self.marker_time_window
        
        # Draw markers in the visible time window
        for marker_time, marker_channel, marker_type, description in self.event_markers:
            if marker_channel != channel and channel != "Both":
                continue
            
            if marker_time < time_min or marker_time > current_time:
                continue
            
            # Get marker info
            marker_info = EVENT_MARKERS.get(marker_type, ('Unknown', 'gray', 'o'))
            color, marker_style = marker_info[1], marker_info[2]
            
            # Get Y position (find corresponding data point)
            if channel == "Atrial" or (channel == "Both" and marker_channel == "Atrial"):
                if len(self.atrial_data) > 0:
                    # Find closest time index
                    time_arr = np.array(self.time_data)
                    idx = np.argmin(np.abs(time_arr - marker_time))
                    if idx < len(self.atrial_data):
                        y_pos = list(self.atrial_data)[idx] * self.gain
                        marker_line, = ax.plot(marker_time, y_pos, marker=marker_style, color=color, 
                               markersize=8, alpha=0.7, linestyle='None')
                        self.marker_artists_atrial.append(marker_line)
                        # Add text annotation
                        ann = ax.annotate(marker_type, xy=(marker_time, y_pos), 
                                   xytext=(5, 5), textcoords='offset points',
                                   fontsize=7, color=color, alpha=0.8)
                        self.annotation_artists_atrial.append(ann)
            
            if channel == "Ventricular" or (channel == "Both" and marker_channel == "Ventricular"):
                if len(self.ventricular_data) > 0:
                    time_arr = np.array(self.time_data)
                    idx = np.argmin(np.abs(time_arr - marker_time))
                    if idx < len(self.ventricular_data):
                        y_pos = list(self.ventricular_data)[idx] * self.gain
                        marker_line, = ax.plot(marker_time, y_pos, marker=marker_style, color=color, 
                               markersize=8, alpha=0.7, linestyle='None')
                        self.marker_artists_ventricular.append(marker_line)
                        ann = ax.annotate(marker_type, xy=(marker_time, y_pos), 
                                   xytext=(5, 5), textcoords='offset points',
                                   fontsize=7, color=color, alpha=0.8)
                        self.annotation_artists_ventricular.append(ann)
    
    def add_egram_data(self, atrial_value: float, ventricular_value: float, timestamp_ms: float):
        """Add new egram data point from serial communication."""
        self.time_data.append(timestamp_ms)
        self.atrial_data.append(atrial_value)
        self.ventricular_data.append(ventricular_value)
    
    def add_event_marker(self, timestamp_ms: float, channel: str, marker_type: str, description: str = ""):
        """Add an event marker to the display."""
        self.event_markers.append((timestamp_ms, channel, marker_type, description))
        # Keep only recent markers (last 10 seconds)
        current_time = time.time() * 1000
        self.event_markers = [
            (t, ch, mt, d) for t, ch, mt, d in self.event_markers
            if current_time - t < 10000
        ]
    
    def on_session_start(self):
        """Called when user logs in."""
        self._clear_display()
        if self.is_streaming:
            self._stop_egram()

