from __future__ import annotations
import tkinter as tk
from tkinter import ttk, messagebox

class WelcomeFrame(ttk.Frame):
    def __init__(self, parent, app):
        super().__init__(parent)
        self.app = app

        # shared container so we can swap views
        self._content = ttk.Frame(self)
        self._content.place(relx=0.5, rely=0.5, anchor="center")

        # entry handles for both views
        self.l_user: ttk.Entry | None = None
        self.l_pass: ttk.Entry | None = None
        self.r_user: ttk.Entry | None = None
        self.r_pass: ttk.Entry | None = None

        self._show_login()

    # ---------- view switching ----------
    def _clear_content(self):
        for w in self._content.winfo_children():
            w.destroy()

    def _show_login(self):
        self._clear_content()

        title = ttk.Label(self._content, text="3K04 Device Controller–Monitor", font=("Segoe UI", 20, "bold"))
        subtitle = ttk.Label(self._content, font=("Segoe UI", 12))
        title.grid(row=0, column=0, pady=(0,8))
        subtitle.grid(row=1, column=0, pady=(0,20))

        # Login Card
        login_card = ttk.Frame(self._content, style="Card.TFrame", padding=16)
        login_card.grid(row=2, column=0, sticky="nsew")

        ttk.Label(login_card, text="Login", font=("Segoe UI", 12, "bold")).grid(row=0, column=0, columnspan=2, pady=(0,8))

        ttk.Label(login_card, text="Username").grid(row=1, column=0, sticky="w")
        self.l_user = ttk.Entry(login_card, width=28)
        self.l_user.grid(row=1, column=1)

        ttk.Label(login_card, text="Password").grid(row=2, column=0, sticky="w")
        self.l_pass = ttk.Entry(login_card, show="*", width=28)
        self.l_pass.grid(row=2, column=1)

        # Login button
        ttk.Button(login_card, text="Login", command=self._login)\
            .grid(row=3, column=0, columnspan=2, pady=(10,4), sticky="ew")

        # Small Register nav button under password box
        small_row = ttk.Frame(login_card)
        small_row.grid(row=4, column=0, columnspan=2, sticky="w")
        ttk.Button(small_row, text="Register", command=self._show_register)\
            .pack(side="left")

        # Keyboard affordance
        self.l_user.focus_set()
        self.l_pass.bind("<Return>", lambda _e: self._login())

        footer = ttk.Label(self._content)
        footer.grid(row=3, column=0, pady=(14,0))

    def _show_register(self):
        self._clear_content()

        title = ttk.Label(self._content, text="Create Account", font=("Segoe UI", 20, "bold"))
        title.grid(row=0, column=0, pady=(0,8))

        reg_card = ttk.Frame(self._content, style="Card.TFrame", padding=16)
        reg_card.grid(row=2, column=0, sticky="nsew")

        ttk.Label(reg_card, text="Register", font=("Segoe UI", 12, "bold")).grid(row=0, column=0, columnspan=2, pady=(0,8))

        ttk.Label(reg_card, text="Username").grid(row=1, column=0, sticky="w")
        self.r_user = ttk.Entry(reg_card, width=28)
        self.r_user.grid(row=1, column=1)

        ttk.Label(reg_card, text="Password (8+ chars)").grid(row=2, column=0, sticky="w")
        self.r_pass = ttk.Entry(reg_card, show="*", width=28)
        self.r_pass.grid(row=2, column=1)

        ttk.Button(reg_card, text="Create Account", command=self._register)\
            .grid(row=3, column=0, columnspan=2, pady=(10,4), sticky="ew")

        # Small back-to-login button
        small_row = ttk.Frame(reg_card)
        small_row.grid(row=4, column=0, columnspan=2, sticky="w")
        ttk.Button(small_row, text="Back to Login", command=self._show_login)\
            .pack(side="left")

        self.r_user.focus_set()
        self.r_pass.bind("<Return>", lambda _e: self._register())

    def _login(self):
        u = self.l_user.get().strip() if self.l_user else ""
        p = self.l_pass.get().strip() if self.l_pass else ""
        if not u or not p:
            messagebox.showwarning("Missing info", "Please enter username and password.")
            return
        if self.app.store.verify_user(u, p):
            self.app.login_success(u)
        else:
            messagebox.showerror("Login failed", "Invalid username or password.")

    def _register(self):
        u = self.r_user.get().strip() if self.r_user else ""
        p = self.r_pass.get().strip() if self.r_pass else ""
        if not u or not p:
            messagebox.showwarning("Missing info", "Please enter username and password.")
            return
        if len(p) < 8:
            messagebox.showwarning("Weak password", "Please choose a password with at least 8 characters.")
            return
        if self.app.store.user_count() >= 10:
            messagebox.showerror("Limit reached", "Maximum of 10 users already registered.")
            return
        if self.app.store.has_user(u):
            messagebox.showerror("Exists", "That username is already taken.")
            return

        ok = self.app.store.add_user(u, p)
        if ok:
            messagebox.showinfo("Account created", "Registration successful. You can now log in.")
            # Return to Login view with username prefilled
            self._show_login()
            if self.l_user:
                self.l_user.delete(0, tk.END)
                self.l_user.insert(0, u)
            if self.l_pass:
                self.l_pass.delete(0, tk.END)
                self.l_pass.focus_set()
        else:
            messagebox.showerror("Registration failed", "Could not create account. Please try a different username.")

    def on_logout(self):
        """Ensure that logout returns user to the login screen."""
        self._show_login()