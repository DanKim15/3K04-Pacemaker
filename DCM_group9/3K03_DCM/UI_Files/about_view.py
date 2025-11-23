from __future__ import annotations
from tkinter import ttk

class AboutView(ttk.Frame):
    def __init__(self, parent, app):
        super().__init__(parent, padding=12)
        text = (
            "Device Controller - Monitor (DCM) - Deliverable 2\n\n"
            "- An interactive front-end only: login, parameter entry, mode selection, local storage.\n"
            "- Efficient JSON storage file: dcm_config.json (hashed passwords and user/user profile information).\n"
            "- Includes Serial Communication via UART (NEED TO IMPLEMENT EGRAM TAB)\n"
        )
        ttk.Label(self, text=text, justify="left").pack(anchor="w")