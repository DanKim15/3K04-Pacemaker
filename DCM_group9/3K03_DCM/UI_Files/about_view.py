from __future__ import annotations
from tkinter import ttk

class AboutView(ttk.Frame):
    def __init__(self, parent, app):
        super().__init__(parent, padding=12)
        text = (
            "Device Controller–Monitor (DCM) – Deliverable 1\n\n"
            "• Front-end only: login, parameter entry, mode selection, local storage.\n"
            "• JSON storage file: dcm_config.json (hashed passwords).\n"
        )
        ttk.Label(self, text=text, justify="left").pack(anchor="w")