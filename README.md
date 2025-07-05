# 🎮 GamepadWatcher

> A lightweight background utility for Windows that simulates `Alt+F4` when your gamepad disconnects.  
> Perfect for auto-closing Steam Big Picture or fullscreen apps launched by a controller.

---

## ✨ Features

- ✅ Monitors gamepad connection via XInput
- 🎯 Sends `Alt+F4` when controller disconnects
- 💤 Runs silently in the background (no console window)
- 🔌 Works with any Xbox-compatible (XInput) gamepad
- 💾 Portable `.exe`, no install required

---

## 📦 Download

👉 [Latest release](https://github.com/your_username/GamepadWatcher/releases/latest)

> You’ll find a zipped `.exe` ready to run. No setup needed.

---

## 🧑‍💻 How It Works

1. The app uses `XInputGetState` to check if a gamepad is connected.
2. If the gamepad was connected and then disappears — it triggers `Alt+F4`.
3. Use this to automatically exit:
   - Steam Big Picture Mode
   - Fullscreen games or apps
   - Emulators launched with a pad

---
