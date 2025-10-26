"""
SFWRENG/MECHTRON 3K04 – Deliverable 1
Device Controller–Monitor (DCM) – Front-End Only (No serial comms)

Features
- Welcome screen with Login and Register (up to 10 local users)
- JSON-backed storage for users and per-user parameters
- Dashboard with tabs:
  • Modes (AOO, VOO, AAI, VVI)
  • Parameters (LRL, URL, Atrial/Ventricular Amplitude & Pulse Width, ARP, VRP)
  • Profiles (Save/Load parameter sets per user)
  • About (course & build info)
- Input validation and helpful error messages
- Clear separation of concerns for easy expansion in Deliverable 2

How to run
- Python 3.9+
- No 3rd‑party dependencies (uses tkinter in the stdlib)
- Run:  python app.py

Data file
- ./dcm_config.json (auto-created on first run)

NOTE (per Deliverable 1):
This is a presentation-layer only application. No serial/Simulink integration yet.
"""
from __future__ import annotations
import json
import os
import hashlib
from dataclasses import dataclass, asdict
from typing import Dict, Any, Optional
import tkinter as tk
from tkinter import ttk, messagebox

CONFIG_PATH = os.path.join(os.path.abspath(os.path.dirname(__file__)), "dcm_config.json")
MAX_USERS = 10

# ------------------------- Data Layer -------------------------
@dataclass
class User:
    username: str
    password_hash: str  # SHA-256

@dataclass
class Parameters:
    # Minimal required for D1
    LRL: int = 60   # Lower Rate Limit (ppm)
    URL: int = 120  # Upper Rate Limit (ppm)
    AtrialAmplitude: float = 3.5  # V (regulated)
    AtrialPulseWidth: float = 1.0  # ms
    VentricularAmplitude: float = 3.5  # V (regulated)
    VentricularPulseWidth: float = 1.0  # ms
    ARP: int = 250  # ms – Atrial Refractory Period
    VRP: int = 320  # ms – Ventricular Refractory Period
    Mode: str = "AOO"  # Default

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
        payload = {
            "users": {},  # username -> {password_hash}
            "profiles": {}  # username -> {profile_name: Parameters}
        }
        with open(self.path, "w", encoding="utf-8") as f:
            json.dump(payload, f, indent=2)

    def _load(self):
        with open(self.path, "r", encoding="utf-8") as f:
            self.data = json.load(f)
        if "users" not in self.data:
            self.data["users"] = {}
        if "profiles" not in self.data:
            self.data["profiles"] = {}

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
        # initialize empty profile map for user
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
    return hashlib.sha256(pw.encode("utf-8")).hexdigest()

# ------------------------- Validation -------------------------
class Validator:
    """Basic input validation consistent with D1 goals (no device comms)."""

    @staticmethod
    def validate(params: Dict[str, Any]) -> tuple[bool, str]:
        # Coerce types and check logical constraints
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

        # Minimal sanity checks (delivery 1 – keep permissive; adjust in D2)
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

# ------------------------- UI -------------------------
class App(tk.Tk):
    def __init__(self, store: DCMStore):
        super().__init__()
        self.title("3K04 DCM – Deliverable 1")
        self.geometry("980x620")
        self.minsize(880, 560)
        self.store = store
        self.active_user: Optional[str] = None
        self._style()
        self._build()

    def _style(self):
        style = ttk.Style(self)
        try:
            self.call("source", "sun-valley.tcl")  # optional theme if available
            self.call("set_theme", "light")
        except tk.TclError:
            pass
        style.configure("TButton", padding=6)
        style.configure("TEntry", padding=4)
        style.configure("Card.TFrame", relief="groove", borderwidth=1)

    def _build(self):
        self.container = ttk.Frame(self)
        self.container.pack(fill=tk.BOTH, expand=True)
        self.frames: Dict[str, tk.Frame] = {}
        for F in (WelcomeFrame, DashboardFrame):
            frame = F(parent=self.container, app=self)
            self.frames[F.__name__] = frame
            frame.grid(row=0, column=0, sticky="nsew")
        self.container.grid_rowconfigure(0, weight=1)
        self.container.grid_columnconfigure(0, weight=1)
        self.show("WelcomeFrame")

    def show(self, name: str):
        frame = self.frames[name]
        frame.tkraise()

    # Session helpers
    def login_success(self, username: str):
        self.active_user = username
        dash: DashboardFrame = self.frames["DashboardFrame"]
        dash.on_session_start(username)
        self.show("DashboardFrame")

    def logout(self):
        self.active_user = None
        self.show("WelcomeFrame")


class WelcomeFrame(ttk.Frame):
    def __init__(self, parent, app: App):
        super().__init__(parent)
        self.app = app
        self._build()

    def _build(self):
        wrapper = ttk.Frame(self)
        wrapper.place(relx=0.5, rely=0.5, anchor="center")

        title = ttk.Label(wrapper, text="3K04 Device Controller–Monitor", font=("Segoe UI", 20, "bold"))
        subtitle = ttk.Label(wrapper, text="Deliverable 1 – Front-End Only", font=("Segoe UI", 12))
        title.grid(row=0, column=0, columnspan=2, pady=(0,8))
        subtitle.grid(row=1, column=0, columnspan=2, pady=(0,20))

        # Login Card
        login_card = ttk.Frame(wrapper, style="Card.TFrame", padding=16)
        ttk.Label(login_card, text="Login", font=("Segoe UI", 12, "bold")).grid(row=0, column=0, columnspan=2, pady=(0,8))
        ttk.Label(login_card, text="Username").grid(row=1, column=0, sticky="w")
        self.l_user = ttk.Entry(login_card, width=28)
        self.l_user.grid(row=1, column=1)
        ttk.Label(login_card, text="Password").grid(row=2, column=0, sticky="w")
        self.l_pass = ttk.Entry(login_card, show="*", width=28)
        self.l_pass.grid(row=2, column=1)
        ttk.Button(login_card, text="Login", command=self._login).grid(row=3, column=0, columnspan=2, pady=(10,0), sticky="ew")
        login_card.grid(row=2, column=0, padx=(0,12), sticky="nsew")

        # Register Card
        reg_card = ttk.Frame(wrapper, style="Card.TFrame", padding=16)
        ttk.Label(reg_card, text="Register", font=("Segoe UI", 12, "bold")).grid(row=0, column=0, columnspan=2, pady=(0,8))
        ttk.Label(reg_card, text="Username").grid(row=1, column=0, sticky="w")
        self.r_user = ttk.Entry(reg_card, width=28)
        self.r_user.grid(row=1, column=1)
        ttk.Label(reg_card, text="Password (8+ chars)").grid(row=2, column=0, sticky="w")
        self.r_pass = ttk.Entry(reg_card, show="*", width=28)
        self.r_pass.grid(row=2, column=1)
        ttk.Button(reg_card, text="Create Account", command=self._register).grid(row=3, column=0, columnspan=2, pady=(10,0), sticky="ew")
        reg_card.grid(row=2, column=1, sticky="nsew")

        # Footer
        footer = ttk.Label(wrapper, text="Tip: Up to 10 users are stored locally in dcm_config.json")
        footer.grid(row=3, column=0, columnspan=2, pady=(14,0))

    def _login(self):
        u = self.l_user.get().strip()
        p = self.l_pass.get().strip()
        if not u or not p:
            messagebox.showwarning("Missing info", "Please enter username and password.")
            return
        if self.app.store.verify_user(u, p):
            self.app.login_success(u)
        else:
            messagebox.showerror("Login failed", "Invalid username or password.")

    def _register(self):
        u = self.r_user.get().strip()
        p = self.r_pass.get().strip()
        if not u or not p:
            messagebox.showwarning("Missing info", "Please enter username and password.")
            return
        if len(p) < 8:
            messagebox.showwarning("Weak password", "Please choose a password with at least 8 characters.")
            return
        if self.app.store.user_count() >= MAX_USERS:
            messagebox.showerror("Limit reached", f"Maximum of {MAX_USERS} users already registered.")
            return
        if self.app.store.has_user(u):
            messagebox.showerror("Exists", "That username is already taken.")
            return
        ok = self.app.store.add_user(u, p)
        if ok:
            messagebox.showinfo("Account created", "Registration successful. You can now log in.")
            self.r_user.delete(0, tk.END)
            self.r_pass.delete(0, tk.END)
        else:
            messagebox.showerror("Registration failed", "Could not create account. Please try a different username.")


class DashboardFrame(ttk.Frame):
    def __init__(self, parent, app: App):
        super().__init__(parent)
        self.app = app
        self.username: Optional[str] = None
        self.current_params: Dict[str, Any] = Parameters.default_dict()
        self._build()

    def _build(self):
        # Top bar
        top = ttk.Frame(self, padding=(10,8))
        self.user_label = ttk.Label(top, text="—", font=("Segoe UI", 10))
        self.btn_logout = ttk.Button(top, text="Logout", command=self.app.logout)
        top.pack(fill=tk.X)
        self.user_label.pack(side=tk.LEFT)
        self.btn_logout.pack(side=tk.RIGHT)

        # Tabs
        self.tabs = ttk.Notebook(self)
        self.tab_modes = ttk.Frame(self.tabs, padding=12)
        self.tab_params = ttk.Frame(self.tabs, padding=12)
        self.tab_profiles = ttk.Frame(self.tabs, padding=12)
        self.tab_about = ttk.Frame(self.tabs, padding=12)

        self.tabs.add(self.tab_modes, text="Modes")
        self.tabs.add(self.tab_params, text="Parameters")
        self.tabs.add(self.tab_profiles, text="Profiles")
        self.tabs.add(self.tab_about, text="About")
        self.tabs.pack(fill=tk.BOTH, expand=True)

        # Build content
        self._build_modes()
        self._build_params()
        self._build_profiles()
        self._build_about()

    def on_session_start(self, username: str):
        self.username = username
        self.user_label.config(text=f"Logged in as: {username}")
        # Load last used params if a special profile exists
        last = self.app.store.load_profile(username, "__last__")
        if last:
            self.current_params.update(last)
        self._refresh_params_ui()
        self._refresh_profiles_list()

    # ----- MODES -----
    def _build_modes(self):
        ttk.Label(self.tab_modes, text="Select Pacing Mode", font=("Segoe UI", 12, "bold")).pack(anchor="w")
        self.mode_var = tk.StringVar(value=self.current_params.get("Mode", "AOO"))
        options = [("AOO – Atrial Asynchronous", "AOO"),
                   ("VOO – Ventricular Asynchronous", "VOO"),
                   ("AAI – Atrial Demand", "AAI"),
                   ("VVI – Ventricular Demand", "VVI")]
        grp = ttk.Frame(self.tab_modes)
        grp.pack(anchor="w", pady=(6,12))
        for i, (label, val) in enumerate(options):
            ttk.Radiobutton(grp, text=label, value=val, variable=self.mode_var, command=self._on_mode_change).grid(row=i, column=0, sticky="w", pady=2)

        note = ttk.Label(self.tab_modes, text="Note: In Deliverable 1, mode changes affect only the UI & stored parameters.")
        note.pack(anchor="w", pady=(8,0))

    def _on_mode_change(self):
        self.current_params["Mode"] = self.mode_var.get()
        messagebox.showinfo("Mode updated", f"Mode set to {self.current_params['Mode']}")

    # ----- PARAMETERS -----
    def _build_params(self):
        grid = ttk.Frame(self.tab_params)
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
        self.param_vars: Dict[str, tk.StringVar] = {}
        for r, (label, key) in enumerate(fields):
            ttk.Label(grid, text=label).grid(row=r, column=0, sticky="w", pady=4, padx=(0,8))
            var = tk.StringVar()
            self.param_vars[key] = var
            ttk.Entry(grid, textvariable=var, width=16).grid(row=r, column=1, sticky="w")

        btns = ttk.Frame(self.tab_params)
        btns.pack(anchor="w", pady=(12,0))
        ttk.Button(btns, text="Apply Changes", command=self._apply_params).grid(row=0, column=0, padx=(0,6))
        ttk.Button(btns, text="Reset to Defaults", command=self._reset_params).grid(row=0, column=1)

        help_text = (
            "Validation rules (D1):\n"
            "• URL must be > LRL.\n"
            "• Amplitudes: 0.1–5.0 V, Pulse widths: 0.1–30 ms.\n"
            "• ARP/VRP: 100–500 ms.\n"
            "Ranges will be refined in D2 per course specs."
        )
        ttk.Label(self.tab_params, text=help_text, foreground="#444").pack(anchor="w", pady=(12,0))

    def _refresh_params_ui(self):
        # Sync data->UI
        self.mode_var.set(self.current_params.get("Mode", "AOO"))
        for k, var in self.param_vars.items():
            var.set(str(self.current_params.get(k, Parameters.default_dict()[k])))

    def _apply_params(self):
        # Collect from UI
        candidate = dict(self.current_params)
        for k, var in self.param_vars.items():
            candidate[k] = var.get()
        candidate["Mode"] = self.mode_var.get()

        ok, msg = Validator.validate(candidate)
        if not ok:
            messagebox.showerror("Invalid parameters", msg)
            return
        # Cast values properly
        candidate["LRL"] = int(candidate["LRL"]) 
        candidate["URL"] = int(candidate["URL"]) 
        candidate["AtrialAmplitude"] = float(candidate["AtrialAmplitude"]) 
        candidate["AtrialPulseWidth"] = float(candidate["AtrialPulseWidth"]) 
        candidate["VentricularAmplitude"] = float(candidate["VentricularAmplitude"]) 
        candidate["VentricularPulseWidth"] = float(candidate["VentricularPulseWidth"]) 
        candidate["ARP"] = int(candidate["ARP"]) 
        candidate["VRP"] = int(candidate["VRP"]) 

        self.current_params.update(candidate)
        # Persist as last-used profile
        assert self.username
        self.app.store.save_profile(self.username, "__last__", self.current_params)
        messagebox.showinfo("Saved", "Parameters updated and saved as last-used for this user.")

    def _reset_params(self):
        self.current_params = Parameters.default_dict()
        self._refresh_params_ui()

    # ----- PROFILES -----
    def _build_profiles(self):
        wrap = ttk.Frame(self.tab_profiles)
        wrap.pack(fill=tk.BOTH, expand=True)

        left = ttk.Frame(wrap)
        left.pack(side=tk.LEFT, fill=tk.Y, padx=(0,12))
        ttk.Label(left, text="Saved Profiles", font=("Segoe UI", 11, "bold")).pack(anchor="w")
        self.profile_list = tk.Listbox(left, height=14)
        self.profile_list.pack(fill=tk.Y, expand=False, pady=(6,6))
        btn_box = ttk.Frame(left)
        btn_box.pack(anchor="w")
        ttk.Button(btn_box, text="Load", command=self._load_selected).grid(row=0, column=0, padx=(0,6))
        ttk.Button(btn_box, text="Delete", command=self._delete_selected).grid(row=0, column=1)

        right = ttk.Frame(wrap)
        right.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        ttk.Label(right, text="Save Current Parameters as Profile", font=("Segoe UI", 11, "bold")).pack(anchor="w")
        form = ttk.Frame(right)
        form.pack(anchor="w", pady=(6,0))
        ttk.Label(form, text="Profile name").grid(row=0, column=0, padx=(0,8))
        self.profile_name_var = tk.StringVar()
        ttk.Entry(form, textvariable=self.profile_name_var, width=24).grid(row=0, column=1)
        ttk.Button(right, text="Save Profile", command=self._save_profile).pack(anchor="w", pady=(8,0))

        note = (
            "Profiles are saved locally per user in dcm_config.json.\n"
            "The special profile '__last__' stores your last-used parameters."
        )
        ttk.Label(right, text=note, foreground="#444").pack(anchor="w", pady=(10,0))

    def _refresh_profiles_list(self):
        self.profile_list.delete(0, tk.END)
        if not self.username:
            return
        profiles = self.app.store.get_profiles(self.username)
        for name in sorted(profiles.keys()):
            if name == "__last__":
                continue
            self.profile_list.insert(tk.END, name)

    def _save_profile(self):
        name = self.profile_name_var.get().strip()
        if not name:
            messagebox.showwarning("Missing name", "Please enter a profile name.")
            return
        if name == "__last__":
            messagebox.showwarning("Reserved name", "'__last__' is reserved. Choose a different name.")
            return
        assert self.username
        self.app.store.save_profile(self.username, name, dict(self.current_params))
        self._refresh_profiles_list()
        messagebox.showinfo("Saved", f"Profile '{name}' saved for {self.username}.")

    def _load_selected(self):
        sel = self.profile_list.curselection()
        if not sel:
            messagebox.showwarning("No selection", "Please select a profile to load.")
            return
        name = self.profile_list.get(sel[0])
        assert self.username
        payload = self.app.store.load_profile(self.username, name)
        if not payload:
            messagebox.showerror("Not found", "Profile could not be loaded.")
            return
        ok, msg = Validator.validate(payload)
        if not ok:
            messagebox.showerror("Invalid profile", f"Stored profile failed validation: {msg}")
            return
        self.current_params.update(payload)
        self._refresh_params_ui()
        messagebox.showinfo("Loaded", f"Profile '{name}' loaded.")

    def _delete_selected(self):
        sel = self.profile_list.curselection()
        if not sel:
            return
        name = self.profile_list.get(sel[0])
        if messagebox.askyesno("Delete profile", f"Delete profile '{name}'?"):
            # Remove and save
            assert self.username
            profiles = self.app.store.get_profiles(self.username)
            if name in profiles:
                del profiles[name]
                self.app.store._save()
                self._refresh_profiles_list()

    # ----- ABOUT -----
    def _build_about(self):
        text = (
            "Device Controller–Monitor (DCM) – Deliverable 1\n\n"
            "• Front-end only: login, parameter entry, mode selection, local storage.\n"
            "• Built with tkinter (stdlib).\n"
            "• JSON storage file: dcm_config.json (hashed passwords).\n\n"
            "Next in Deliverable 2:\n"
            "• Add serial communications (UART over USB) to exchange parameters and egrams.\n"
            "• Expand modes and parameters per course spec.\n"
        )
        ttk.Label(self.tab_about, text=text, justify=tk.LEFT).pack(anchor="w")


def main():
    store = DCMStore(CONFIG_PATH)
    app = App(store)
    app.mainloop()

if __name__ == "__main__":
    main()