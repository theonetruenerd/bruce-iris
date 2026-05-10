# TODO List: Cyberdeck & Iris AI Project

## 🛠️ Hardware Integration (Peripherals)
- [ ] **I2C 6-Bus Hub:** Connect and verify communication with multiple sensors.
- [ ] **Offline Voice Recognition:** Finalize integration of Grove Voice sensor for "Iris" commands.
- [ ] **Thermal Imaging Camera:** Implement display driver and UI for thermal visuals.
- [ ] **NFC Reader (PN532/Killer):** Integrate for card cloning and spoofing.
- [ ] **Biometrics:**
    - [ ] **Heart Rate Sensor:** Implement real-time monitoring.
    - [ ] **Galvanic Stress Response (GSR):** Implement stress level detection for "Bio-rhythms" telemetry.
- [ ] **Magnetic Wristband:** Design/Source and adapt Cardputer for wearable mounting.

## 🤖 "Iris" AI Assistant Development
- [ ] **Command Mapping:** Map `iris_cyberpunk_commands.md` to actual firmware functions (e.g., WiFi, BLE, IR).
- [ ] **Voice Aliases:** Update `grove_voice.cpp` to use Iris personas instead of default AC commands.
- [ ] **Cyberpunk UI/Aesthetics:**
    - [ ] Implement "Neon Mode" (High contrast Neon Green/Magenta theme).
    - [ ] Add tactical "Status Check" display (Battery, Kernel status, Signal noise).
    - [ ] Integrate low-bitrate synth feedback sounds for Iris responses.

## 🧥 Wearables & Aesthetics
- [ ] **Cyberpunk Jacket Integration:**
    - [ ] Research/Implement communication protocol with Adafruit Flora wearables.
    - [ ] Sync Cardputer events (e.g., "Signal Breach") with jacket LED patterns.
- [ ] **Hot-Swappable "Cyberdeck" Chassis:**
    - [ ] Design/3D Print custom cases for modular peripherals.
    - [ ] Ensure "hot-swappable" physical connection stability.

## 📁 System & Infrastructure
- [ ] **Documentation:** Update wiki with "Iris" command matrix and module wiring diagrams.
- [ ] **Optimization:** Ensure firmware stability when running multiple I2C sensors simultaneously.
- [ ] **Session Logs:** Implement "Purge Memory" / "Scrub Logs" functionality for operational security.
