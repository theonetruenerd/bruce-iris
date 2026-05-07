#include "voice_recognition_app.h"
#include "grove_voice.h"
#include "core/display.h"
#include "core/mykeyboard.h"
#include <globals.h>

void voice_recognition_app() {
    tft.fillScreen(bruceConfig.bgColor);
    printTitle("Voice Recognition");
    printFootnote("Press any key to exit");
    
    if (!groveVoice.begin()) {
        displayError("Failed to init Grove Voice", true);
        return;
    }

    String lastCommand = "Waiting for command...";
    uint8_t lastCmdCode = 0xFF;
    
    tft.setTextSize(FM);
    tft.setTextColor(bruceConfig.priColor);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(lastCommand, tft.width() / 2, tft.height() / 2);
    
    bool exitApp = false;
    while (!exitApp) {
        if (groveVoice.available() >= 5) {
            uint8_t cmd = groveVoice.readCommand();
            if (cmd != 0xFF) {
                lastCmdCode = cmd;
                lastCommand = groveVoice.getCommandText(cmd);
                
                // Clear middle area
                tft.fillRect(0, 30, tft.width(), tft.height() - 60, bruceConfig.bgColor);
                
                // Draw command
                tft.setTextSize(FM);
                tft.setTextColor(bruceConfig.priColor);
                tft.drawString(lastCommand, tft.width() / 2, tft.height() / 2);
                
                // Draw hex code below
                char hexStr[16];
                sprintf(hexStr, "Code: 0x%02X", lastCmdCode);
                tft.setTextSize(FP);
                tft.setTextColor(TFT_DARKGREY);
                tft.drawString(hexStr, tft.width() / 2, tft.height() / 2 + 30);
                
                // Handle specific commands
                if (cmd == groveVoice.getWakeWordCode()) {
                    // Wake word detected - visual feedback
                    tft.fillCircle(10, 10, 5, TFT_YELLOW);
                    delay(100);
                    tft.fillCircle(10, 10, 5, bruceConfig.bgColor);
                }
            }
        }
        
        // Check for exit
        if (check(AnyKeyPress)) {
            exitApp = true;
        }
        
        delay(10);
    }
    
    groveVoice.end();
}
