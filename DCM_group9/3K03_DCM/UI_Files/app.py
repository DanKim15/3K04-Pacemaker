# ------------------------------
# File: app.py
# ------------------------------
from __future__ import annotations
import json
import os
import hashlib
from dataclasses import dataclass, asdict
from typing import Dict, Any, Optional
import tkinter as tk
from tkinter import ttk, messagebox

# Local views
from registration_view import WelcomeFrame
from modes_view import ModesView
from parameters_view import ParametersView
from profiles_view import ProfilesView
from dcm_visuals_view import DCMVisualsView
from about_view import AboutView

CONFIG_PATH = os.path.join(os.path.abspath(os.path.dirname(__file__)), "dcm_config.json")
MAX_USERS = 10

# ------------------------- Data Layer -------------------------
@dataclass
class Parameters:
    LRL: int = 60
    URL: int = 120
    AtrialAmplitude: float = 3.5
    AtrialPulseWidth: float = 1.0
    VentricularAmplitude: float = 3.5
    VentricularPulseWidth: float = 1.0
    ARP: int = 250
    VRP: int = 320
    Mode: str = "AOO"

    @staticmethod
    def default_dict() -> Dict[str, Any]:
        return asdict(Parameters())

class DCMStore:
    """Simple JSON-backed storage for users and per-user settings."""
    def __init__(self, path: str):
        self.path = path
        if not os.path.exists(path):
            self._init_file()
        self._load()

    def _init_file(self):
        payload = {"users": {}, "profiles": {}}
        with open(self.path, "w", encoding="utf-8") as f:
            json.dump(payload, f, indent=2)

    def _load(self):
        with open(self.path, "r", encoding="utf-8") as f:
            self.data = json.load(f)
        self.data.setdefault("users", {})
        self.data.setdefault("profiles", {})

    def _save(self):
        with open(self.path, "w", encoding="utf-8") as f:
            json.dump(self.data, f, indent=2)

    # --- Users ---
    def user_count(self) -> int:
        return len(self.data.get("users", {}))

    def has_user(self, username: str) -> bool:
        return username in self.data.get("users", {})

    def add_user(self, username: str, password: str) -> bool:
        if self.user_count() >= MAX_USERS:
            return False
        if self.has_user(username):
            return False
        ph = hash_pw(password)
        self.data["users"][username] = {"password_hash": ph}
        self.data["profiles"].setdefault(username, {})
        self._save()
        return True

    def verify_user(self, username: str, password: str) -> bool:
        if not self.has_user(username):
            return False
        stored = self.data["users"][username]["password_hash"]
        return stored == hash_pw(password)

    # --- Profiles (per user) ---
    def get_profiles(self, username: str) -> Dict[str, Dict[str, Any]]:
        return self.data.get("profiles", {}).get(username, {})

    def save_profile(self, username: str, profile_name: str, params: Dict[str, Any]):
        self.data.setdefault("profiles", {}).setdefault(username, {})[profile_name] = params
        self._save()

    def load_profile(self, username: str, profile_name: str) -> Optional[Dict[str, Any]]:
        return self.get_profiles(username).get(profile_name)


def hash_pw(pw: str) -> str:
    import hashlib
    return hashlib.sha256(pw.encode("utf-8")).hexdigest()

# ------------------------- Validation -------------------------
class Validator:
    @staticmethod
    def validate(params: Dict[str, Any]) -> tuple[bool, str]:
        try:
            LRL = int(params["LRL"])  # ppm
            URL = int(params["URL"])  # ppm
            AA = float(params["AtrialAmplitude"])   # V
            APW = float(params["AtrialPulseWidth"]) # ms
            VA = float(params["VentricularAmplitude"]) # V
            VPW = float(params["VentricularPulseWidth"]) # ms
            ARP = int(params["ARP"])  # ms
            VRP = int(params["VRP"])  # ms
            Mode = str(params["Mode"]).upper()
        except (KeyError, ValueError) as e:
            return False, f"Invalid input type: {e}"

        if not (30 <= LRL <= 175):
            return False, "LRL should be between 30 and 175 ppm."
        if not (LRL < URL <= 220):
            return False, "URL must be > LRL and ≤ 220 ppm."
        if not (0.1 <= AA <= 5.0):
            return False, "Atrial Amplitude should be 0.1–5.0 V (regulated)."
        if not (0.1 <= VA <= 5.0):
            return False, "Ventricular Amplitude should be 0.1–5.0 V (regulated)."
        if not (0.1 <= APW <= 30.0):
            return False, "Atrial Pulse Width should be 0.1–30 ms."
        if not (0.1 <= VPW <= 30.0):
            return False, "Ventricular Pulse Width should be 0.1–30 ms."
        if not (100 <= ARP <= 500):
            return False, "ARP should be 100–500 ms."
        if not (100 <= VRP <= 500):
            return False, "VRP should be 100–500 ms."
        if Mode not in {"AOO", "VOO", "AAI", "VVI"}:
            return False, "Mode must be one of: AOO, VOO, AAI, VVI."
        return True, "OK"

# ------------------------- Main App -------------------------
class App(tk.Tk):
    def __init__(self, store: DCMStore):
        super().__init__()
        self.title("3K04 DCM – Deliverable 1 (Modular)")
        self.geometry("1000x650")
        self.minsize(900, 580)
        self.store = store
        self.active_user: Optional[str] = None
        self.current_params: Dict[str, Any] = Parameters.default_dict()
        self._device_com: bool = True  # Private variable
        self._other_pacemaker_detected: bool = True  # Private variable
        self._style()
        self._build()
    
    @property
    def device_com(self) -> bool:
        return self._device_com
    
    @device_com.setter
    def device_com(self, value: bool):
        self._device_com = value
        # Auto-update UI when value changes
        if hasattr(self, 'dcm_visuals_view'):
            self.dcm_visuals_view._refresh_status()
    
    @property
    def other_pacemaker_detected(self) -> bool:
        return self._other_pacemaker_detected
    
    @other_pacemaker_detected.setter
    def other_pacemaker_detected(self, value: bool):
        self._other_pacemaker_detected = value
        # Auto-update UI when value changes
        if hasattr(self, 'dcm_visuals_view'):
            self.dcm_visuals_view._refresh_status()

    def _style(self):
        style = ttk.Style(self)
        style.configure("TButton", padding=6)
        style.configure("TEntry", padding=4)
        style.configure("Card.TFrame", relief="groove", borderwidth=1)

    def _build(self):
        self.container = ttk.Frame(self)
        self.container.pack(fill=tk.BOTH, expand=True)

        # Welcome / Registration screen
        self.welcome = WelcomeFrame(self.container, self)
        self.welcome.grid(row=0, column=0, sticky="nsew")

        # Dashboard (tabs)
        self.dashboard = ttk.Frame(self.container)
        self.tabs = ttk.Notebook(self.dashboard)

        # Views
        self.modes_view = ModesView(self.tabs, self)
        self.params_view = ParametersView(self.tabs, self)
        self.profiles_view = ProfilesView(self.tabs, self)
        self.dcm_visuals_view = DCMVisualsView(self.tabs, self)
        self.about_view = AboutView(self.tabs, self)

        self.tabs.add(self.modes_view, text="Modes")
        self.tabs.add(self.params_view, text="Parameters")
        self.tabs.add(self.profiles_view, text="Profiles")
        self.tabs.add(self.dcm_visuals_view, text="DCM Device Visuals")
        self.tabs.add(self.about_view, text="About")

        top = ttk.Frame(self.dashboard, padding=(10,8))
        self.user_label = ttk.Label(top, text="—")
        ttk.Button(top, text="Logout", command=self.logout).pack(side=tk.RIGHT)
        self.user_label.pack(side=tk.LEFT)
        top.pack(fill=tk.X)
        self.tabs.pack(fill=tk.BOTH, expand=True)

        self.container.grid_rowconfigure(0, weight=1)
        self.container.grid_columnconfigure(0, weight=1)
        self.show_welcome()

    def show_welcome(self):
        # Hide dashboard, show welcome and force the login view to be visible
        self.dashboard.grid_forget()
        try:
            # Reset the welcome view to login each time we show it
            if hasattr(self.welcome, "on_logout"):
                self.welcome.on_logout()
        except Exception:
            pass
        self.welcome.grid(row=0, column=0, sticky="nsew")
        self.welcome.tkraise()
        # Force immediate GUI update
        self.update_idletasks()

    def show_dashboard(self):
        self.welcome.grid_forget()
        self.dashboard.grid(row=0, column=0, sticky="nsew")
        # Force immediate GUI update
        self.update_idletasks()

    def login_success(self, username: str):
        self.active_user = username
        self.user_label.config(text=f"Logged in as: {username}")
        # Load last used params profile if exists
        last = self.store.load_profile(username, "__last__")
        if last:
            self.current_params.update(last)
        # Notify views
        self.modes_view.on_session_start()
        self.params_view.on_session_start()
        self.profiles_view.on_session_start()
        self.dcm_visuals_view.on_session_start()
        self.show_dashboard()

    def logout(self):
        # Clear session state and return to login screen (not blank)
        self.active_user = None
        self.user_label.config(text="—")
        self.show_welcome()


def main():
    store = DCMStore(CONFIG_PATH)
    app = App(store)
    app.mainloop()

if __name__ == "__main__":
    main()