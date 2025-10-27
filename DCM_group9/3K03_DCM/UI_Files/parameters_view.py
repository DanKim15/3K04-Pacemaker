from __future__ import annotations
import tkinter as tk
from tkinter import ttk, messagebox

class ParametersView(ttk.Frame):
    RANGES = {
        "LRL": "[30-175 ppm]",
        "URL": "(> LRL) [up to 220 ppm]",
        "AtrialAmplitude": "[0.1-5.0 V]",
        "AtrialPulseWidth": "[0.1-30 ms]",
        "VentricularAmplitude": "[0.1-5.0 V]",
        "VentricularPulseWidth": "[0.1-30 ms]",
        "ARP": "[100-500 ms]",
        "VRP": "[100-500 ms]",
    }

    def __init__(self, parent, app):
        super().__init__(parent, padding=12)
        self.app = app
        self.param_vars: dict[str, tk.StringVar] = {}
        self.mode_var = tk.StringVar(value=self.app.current_params.get("Mode", "AOO"))
        self._build()

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
            ttk.Label(row, text=f"  {self.RANGES[key]}", foreground="#666").pack(side=tk.LEFT)
            var = tk.StringVar()
            self.param_vars[key] = var
            ttk.Entry(row, textvariable=var, width=16).pack(side=tk.LEFT, padx=(10,0))

        btns = ttk.Frame(self)
        btns.pack(anchor="w", pady=(12,0))
        ttk.Button(btns, text="Apply Changes", command=self._apply_params).grid(row=0, column=0, padx=(0,6))
        ttk.Button(btns, text="Reset to Defaults", command=self._reset_params).grid(row=0, column=1)

    def on_session_start(self):
        self._refresh_params_ui()

    def _refresh_params_ui(self):
        for k, var in self.param_vars.items():
            var.set(str(self.app.current_params.get(k)))

    def _apply_params(self):
        candidate = dict(self.app.current_params)
        for k, var in self.param_vars.items():
            candidate[k] = var.get()
        # keep current mode
        candidate["Mode"] = self.app.current_params.get("Mode", "AOO")

        ok, msg = self.app.Validator.validate(candidate) if hasattr(self.app, 'Validator') else ValidatorProxy.validate(candidate)
        if not ok:
            messagebox.showerror("Invalid parameters", msg)
            return
        # Cast values and persist
        candidate["LRL"] = int(candidate["LRL"]) 
        candidate["URL"] = int(candidate["URL"]) 
        candidate["AtrialAmplitude"] = float(candidate["AtrialAmplitude"]) 
        candidate["AtrialPulseWidth"] = float(candidate["AtrialPulseWidth"]) 
        candidate["VentricularAmplitude"] = float(candidate["VentricularAmplitude"]) 
        candidate["VentricularPulseWidth"] = float(candidate["VentricularPulseWidth"]) 
        candidate["ARP"] = int(candidate["ARP"]) 
        candidate["VRP"] = int(candidate["VRP"]) 

        self.app.current_params.update(candidate)
        assert self.app.active_user
        self.app.store.save_profile(self.app.active_user, "__last__", self.app.current_params)
        messagebox.showinfo("Saved", "Parameters updated and saved as last-used for this user.")

    def _reset_params(self):
        # Reset to app's default
        from app import Parameters  # local import to avoid circular at import-time
        self.app.current_params = Parameters.default_dict()
        self._refresh_params_ui()

# Fallback validator when imported standalone
class ValidatorProxy:
    @staticmethod
    def validate(params: dict[str, str]):
        # Minimal duplicate of app.Validator to avoid circular import
        try:
            LRL = int(params["LRL"]) ; URL = int(params["URL"]) 
            AA = float(params["AtrialAmplitude"]) ; APW = float(params["AtrialPulseWidth"]) 
            VA = float(params["VentricularAmplitude"]) ; VPW = float(params["VentricularPulseWidth"]) 
            ARP = int(params["ARP"]) ; VRP = int(params["VRP"]) 
            Mode = str(params["Mode"]).upper()
        except Exception as e:
            return False, f"Invalid input type: {e}"
        if not (30 <= LRL <= 175): return False, "LRL should be between 30 and 175 ppm."
        if not (LRL < URL <= 220): return False, "URL must be > LRL and ≤ 220 ppm."
        if not (0.1 <= AA <= 5.0): return False, "Atrial Amplitude should be 0.1-5.0 V (regulated)."
        if not (0.1 <= VA <= 5.0): return False, "Ventricular Amplitude should be 0.1-5.0 V (regulated)."
        if not (0.1 <= APW <= 30.0): return False, "Atrial Pulse Width should be 0.1-30 ms."
        if not (0.1 <= VPW <= 30.0): return False, "Ventricular Pulse Width should be 0.1-30 ms."
        if not (100 <= ARP <= 500): return False, "ARP should be 100-500 ms."
        if not (100 <= VRP <= 500): return False, "VRP should be 100-500 ms."
        if Mode not in {"AOO", "VOO", "AAI", "VVI"}: return False, "Mode must be one of: AOO, VOO, AAI, VVI."
        return True, "OK"
