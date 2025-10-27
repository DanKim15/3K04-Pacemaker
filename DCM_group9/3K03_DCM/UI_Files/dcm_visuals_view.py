from __future__ import annotations
import tkinter as tk
from tkinter import ttk

class DCMVisualsView(ttk.Frame):
    def __init__(self, parent, app):
        super().__init__(parent, padding=12)
        self.app = app
        self._build()

    def _build(self):
        ttk.Label(self, text="DCM Device Status", font=("Segoe UI", 12, "bold")).pack(anchor="w", pady=(0, 12))
        
        # Create a frame for the communication status display
        comm_frame = ttk.Frame(self, style="Card.TFrame", padding=20)
        comm_frame.pack(fill=tk.X, pady=(0, 12))
        
        ttk.Label(comm_frame, text="Device Communication:", font=("Segoe UI", 11, "bold")).pack(anchor="w", pady=(0, 8))
        
        # Status label for device communication
        self.comm_status_label = ttk.Label(
            comm_frame, 
            text="", 
            font=("Segoe UI", 14, "bold"),
            foreground="#333"
        )
        self.comm_status_label.pack(anchor="w")
        
        # Create a frame for the pacemaker detection status
        pacemaker_frame = ttk.Frame(self, style="Card.TFrame", padding=20)
        pacemaker_frame.pack(fill=tk.X, pady=(0, 12))
        
        ttk.Label(pacemaker_frame, text="Other Pacemaker Detection:", font=("Segoe UI", 11, "bold")).pack(anchor="w", pady=(0, 8))
        
        # Status label for other pacemaker detection
        self.pacemaker_status_label = ttk.Label(
            pacemaker_frame, 
            text="", 
            font=("Segoe UI", 14, "bold"),
            foreground="#333"
        )
        self.pacemaker_status_label.pack(anchor="w")
        
        # Refresh button to manually update the status
        ttk.Button(self, text="Refresh Status", command=self._refresh_status).pack(anchor="w", pady=(12, 0))
        
        # Test buttons
        test_frame = ttk.Frame(self)
        test_frame.pack(anchor="w", pady=(20, 0))
        ttk.Label(test_frame, text="Test Controls:", font=("Segoe UI", 11, "bold")).pack(anchor="w", pady=(0, 8))
        
        btn_row1 = ttk.Frame(test_frame)
        btn_row1.pack(anchor="w", pady=(0, 4))
        ttk.Button(btn_row1, text="Connect Device", command=self._test_connect).pack(side=tk.LEFT, padx=(0, 4))
        ttk.Button(btn_row1, text="Disconnect Device", command=self._test_disconnect).pack(side=tk.LEFT)
        
        btn_row2 = ttk.Frame(test_frame)
        btn_row2.pack(anchor="w")
        ttk.Button(btn_row2, text="Detect Pacemaker", command=self._test_detect_pacemaker).pack(side=tk.LEFT, padx=(0, 4))
        ttk.Button(btn_row2, text="Clear Pacemaker", command=self._test_clear_pacemaker).pack(side=tk.LEFT)
    
    def _test_connect(self):
        """Test button: Connect device"""
        self.app.device_com = True
    
    def _test_disconnect(self):
        """Test button: Disconnect device"""
        self.app.device_com = False
    
    def _test_detect_pacemaker(self):
        """Test button: Detect other pacemaker"""
        self.app.other_pacemaker_detected = True
    
    def _test_clear_pacemaker(self):
        """Test button: Clear other pacemaker"""
        self.app.other_pacemaker_detected = False

    def on_session_start(self):
        """Called when user logs in"""
        self._refresh_status()

    def _refresh_status(self):
        """Update the status displays based on device_com and other_pacemaker_detected variables"""
        # Update device communication status
        if self.app.device_com:
            self.comm_status_label.config(text="Device is communicating", foreground="green")
        else:
            self.comm_status_label.config(text="Device not communicating", foreground="red")
        
        # Update other pacemaker detection status
        if self.app.other_pacemaker_detected:
            self.pacemaker_status_label.config(text="Different pacemaker detected in range", foreground="orange")
        else:
            self.pacemaker_status_label.config(text="No other pacemaker in range", foreground="gray")