from __future__ import annotations
from tkinter import ttk

class AboutView(ttk.Frame):
    def __init__(self, parent, app):
        super().__init__(parent, padding=12)
        text = (
            "Device Controller-Monitor (DCM) - Deliverable 1\n\n"
            "- Interactive Front-end UI: login, parameter inputs, mode selection, and local storage.\n"
            "- Efficient JSON storage file: dcm_config.json (hashed passwords and profiles with profile info).\n"
            "- Modularized view files for scalable development (For Deliverable 2: adding UART serial comms).\n"
        )
        ttk.Label(self, text=text, justify="left").pack(anchor="w")
