# Project Plan: Grove Offline Voice Recognition Integration

This document outlines the plan for integrating the (Seeed Studios) Grove Offline Voice Recognition module into the Bruce firmware, primarily targeting the M5Stack Cardputer.

## 1. Hardware Overview
- **Primary Device:** M5Stack Cardputer (ESP32-S3).
- **Module:** Seeed Studios Grove Offline Voice Recognition (VC-02 based).
- **Connection:** Grove Port (UART).
    - **Cardputer Grove Pins:** SDA (GPIO 2), SCL (GPIO 1).
    - **Communication:** UART at 115200 Baud.
    - **Voltage:** 3.3V / 5V.

## 2. Software Architecture
The integration will follow the Bruce firmware's modular structure.

### 2.1 Driver Layer
- Create a dedicated driver for the VC-02 module.
- Handle UART initialization on the Grove pins.
- Implement an asynchronous listener to capture Hex codes from the module.

### 2.2 Command Framework
- **Default Commands:** Implement a mapping table for the 150+ default commands (e.g., "Turn on the light" -> `0x27`).
- **Action Framework:** Design a registry system where commands can be linked to specific software actions (e.g., UI updates, GPIO toggles, or even triggering other Bruce features).
- **Extensibility:** The framework will allow easy registration of new "Command -> Action" pairs.

### 2.3 User Interface
- Create a new "App" or menu item in Bruce for Voice Recognition.
- Display the last recognized command as text on the screen.
- Visual feedback when the wake word is detected.

## 3. Implementation Steps

### Phase 1: Planning & Setup
- [ ] Create this project plan (Done).
- [ ] Define the command mapping table for default commands.

### Phase 2: Driver Development
- [ ] Implement `GroveVoiceRecognizer` class.
- [ ] Configure UART on pins 1 and 2 (for Cardputer).
- [ ] Implement hex code parsing logic.

### Phase 3: Framework & UI
- [ ] Create the Command Dispatcher.
- [ ] Develop the Voice Recognition App UI in the Bruce framework.
- [ ] Hook the UI to the Driver to display real-time results.

### Phase 4: Refinement & Testing
- [ ] Add support for "Custom Actions" (framework only, for future improvement).
- [ ] Test reliability and responsiveness.

## 4. Default Command Examples (Partial List)
| Hex Code | Command Text |
|----------|--------------|
| 0x00     | Hi, how can I help? |
| 0x01     | See you later |
| 0x27     | Turn on the light |
| 0x28     | Turn off the light |
| ...      | ... |

## 5. Verification Plan
- **Simulation:** Since actual hardware might not be connected during development, I will use a mock serial input to verify the parsing and UI logic.
- **Compilation:** Ensure the code compiles for the `m5stack-cardputer` environment.
