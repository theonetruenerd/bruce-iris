#pragma once

#include <Arduino.h>
#include <vector>

struct VoiceCommand {
    uint8_t cmd;
    const char* text;
};

extern const std::vector<VoiceCommand> defaultVoiceCommands;

class GroveVoice {
public:
    GroveVoice();
    bool begin(int rxPin = -1, int txPin = -1);
    void end();
    int available();
    uint8_t readCommand();
    const char* getCommandText(uint8_t cmd);
    
    void addAlias(uint8_t cmd, const char* text);
    void clearAliases();
    void setWakeWordCode(uint8_t cmd);
    uint8_t getWakeWordCode() const;
    
private:
    HardwareSerial* _serial;
    int _rxPin;
    int _txPin;
    std::vector<VoiceCommand> _aliases;
    uint8_t _wakeWordCode;
};

extern GroveVoice groveVoice;
