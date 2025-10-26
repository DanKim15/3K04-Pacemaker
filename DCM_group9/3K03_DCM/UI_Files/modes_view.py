# ------------------------------
# File: modes_view.py
# ------------------------------
from __future__ import annotations
import tkinter as tk
from tkinter import ttk, messagebox

class ModesView(ttk.Frame):
    def __init__(self, parent, app):
        super().__init__(parent, padding=12)
        self.app = app
        self.mode_var = tk.StringVar(value=self.app.current_params.get("Mode", "AOO"))
        self._build()

    def _build(self):
        ttk.Label(self, text="Select Pacing Mode", font=("Segoe UI", 12, "bold")).pack(anchor="w")
        options = [
            ("AOO – Atrial Asynchronous", "AOO"),
            ("VOO – Ventricular Asynchronous", "VOO"),
            ("AAI – Atrial Demand", "AAI"),
            ("VVI – Ventricular Demand", "VVI"),
        ]
        grp = ttk.Frame(self)
        grp.pack(anchor="w", pady=(6,12))
        for i, (label, val) in enumerate(options):
            ttk.Radiobutton(grp, text=label, value=val, variable=self.mode_var, command=self._on_mode_change).grid(row=i, column=0, sticky="w", pady=2)

        ttk.Label(self, text="Note: Deliverable 1 is front-end only; mode affects stored parameters only.").pack(anchor="w")

    def on_session_start(self):
        self._refresh_mode_ui()

    def _refresh_mode_ui(self):
        """Refresh the mode selection to match current parameters"""
        self.mode_var.set(self.app.current_params.get("Mode", "AOO"))

    def _on_mode_change(self):
        self.app.current_params["Mode"] = self.mode_var.get()
        messagebox.showinfo("Mode updated", f"Mode set to {self.app.current_params['Mode']}")