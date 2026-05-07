# Grove Offline Voice Recognition (VC-02)

The Grove Offline Voice Recognition module is based on the **Ai-Thinker VC-02** chip (using the Unisound US516P6). 

## Hardware Limitation: Custom Commands & Wake-word
The sounds that the module listens for (the "Wake-word" and the "Command words") are **baked into the module's firmware**. 

You **cannot** change the sounds the module listens for using UART commands from Bruce or any other microcontroller. The `addAlias()` and `setWakeWordCode()` functions in the Bruce firmware only change how the recognized Hex codes are **displayed** on the screen; they do not change the module's recognition engine.

## How to Truly Change Commands/Wake-word
To change the actual voice commands or the wake-word, you must reflash the module's own firmware:

1.  **Use the Web Compiler:** 
    Ai-Thinker provides a web-based platform to generate custom firmware: [Voice.Ai-Thinker.com](http://voice.ai-thinker.com).
    *   Register/Login (Switch to English).
    *   Define your custom wake-word and up to 150 commands.
    *   The platform will generate a firmware image (`.bin` or `.img`).

2.  **Flash the Module:**
    *   Connect the VC-02 module to your PC via a USB-to-UART adapter.
    *   Use the **UniOneUpdateTool** (provided by Ai-Thinker) to flash the generated firmware to the module over UART.
    *   **Warning:** Some firmware versions might disable the UART upgrade protocol. In that case, a JTAG programmer might be required for future updates.

3.  **Update Bruce:**
    Once you have flashed your module with custom commands, they will likely return different Hex codes. Use `groveVoice.addAlias(0xXX, "My Custom Command")` in the Bruce code to map these new codes to the correct text on the display.

## Default Command Table
By default, the module comes with 150+ commands related to home automation (Air conditioning, Lights, etc.). You can find the partial list in `src/modules/others/grove_voice.cpp`.
