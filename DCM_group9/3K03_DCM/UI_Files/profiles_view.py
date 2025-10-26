from __future__ import annotations
import tkinter as tk
from tkinter import ttk, messagebox

class ProfilesView(ttk.Frame):
    def __init__(self, parent, app):
        super().__init__(parent, padding=12)
        self.app = app
        self.profile_name_var = tk.StringVar()
        self._build()

    def _build(self):
        wrap = ttk.Frame(self)
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
        ttk.Entry(form, textvariable=self.profile_name_var, width=24).grid(row=0, column=1)
        ttk.Button(right, text="Save Profile", command=self._save_profile).pack(anchor="w", pady=(8,0))

    def on_session_start(self):
        self._refresh_profiles_list()

    def _refresh_profiles_list(self):
        self.profile_list.delete(0, tk.END)
        if not self.app.active_user:
            return
        profiles = self.app.store.get_profiles(self.app.active_user)
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
        assert self.app.active_user
        self.app.store.save_profile(self.app.active_user, name, dict(self.app.current_params))
        self._refresh_profiles_list()
        messagebox.showinfo("Saved", f"Profile '{name}' saved for {self.app.active_user}.")

    def _load_selected(self):
        sel = self.profile_list.curselection()
        if not sel:
            messagebox.showwarning("No selection", "Please select a profile to load.")
            return
        name = self.profile_list.get(sel[0])
        assert self.app.active_user
        payload = self.app.store.load_profile(self.app.active_user, name)
        if not payload:
            messagebox.showerror("Not found", "Profile could not be loaded.")
            return
        # lightweight validation: ensure keys exist
        required = {"LRL","URL","AtrialAmplitude","AtrialPulseWidth","VentricularAmplitude","VentricularPulseWidth","ARP","VRP","Mode"}
        if not required.issubset(payload):
            messagebox.showerror("Invalid profile", "Stored profile is missing fields.")
            return
        self.app.current_params.update(payload)
        
        # Refresh the Parameters view UI to show the loaded values
        if hasattr(self.app, 'params_view'):
            self.app.params_view._refresh_params_ui()
        
        # Also refresh the Modes view if the mode changed
        if hasattr(self.app, 'modes_view'):
            self.app.modes_view._refresh_mode_ui()
        
        messagebox.showinfo("Loaded", f"Profile '{name}' loaded.")

    def _delete_selected(self):
        sel = self.profile_list.curselection()
        if not sel:
            return
        name = self.profile_list.get(sel[0])
        if messagebox.askyesno("Delete profile", f"Delete profile '{name}'?"):
            assert self.app.active_user
            profiles = self.app.store.get_profiles(self.app.active_user)
            if name in profiles:
                del profiles[name]
                self.app.store._save()
                self._refresh_profiles_list()