#include "grove_voice.h"
#include <globals.h>

const std::vector<VoiceCommand> defaultVoiceCommands = {
    {0x00, "Hi, how can I help?"},
    {0x01, "See you later"},
    {0x02, "Match the air conditioner"},
    {0x03, "Turn on the air conditioner"},
    {0x04, "Turn off the air conditioner"},
    {0x05, "Automatic mode"},
    {0x06, "Cold mode"},
    {0x07, "Heat mode"},
    {0x08, "Dry mode"},
    {0x09, "Fan mode"},
    {0x0a, "Sleeping mode"},
    {0x0b, "Automatic fan"},
    {0x0c, "Low fan"},
    {0x0d, "Medium fan"},
    {0x0e, "High fan"},
    {0x0f, "Higher the fan"},
    {0x10, "Lower the fan"},
    {0x11, "Sixteen centigrade"},
    {0x12, "Seventeen centigrade"},
    {0x13, "Eighteen centigrade"},
    {0x14, "Nineteen centigrade"},
    {0x15, "Twenty centigrade"},
    {0x16, "Twenty one centigrade"},
    {0x17, "Twenty two centigrade"},
    {0x18, "Twenty three centigrade"},
    {0x19, "Twenty four centigrade"},
    {0x1a, "Twenty five centigrade"},
    {0x1b, "Twenty six centigrade"},
    {0x1c, "Twenty seven centigrade"},
    {0x1d, "Twenty eight centigrade"},
    {0x1e, "Twenty nine centigrade"},
    {0x1f, "Thirty centigrade"},
    {0x20, "Warmer"},
    {0x21, "Cooler"},
    {0x22, "Start to fan"},
    {0x23, "Stop to fan"},
    {0x24, "Air swing up and down"},
    {0x25, "Air swing left and right"},
    {0x26, "Air conditioner reset"},
    {0x27, "Turn on the light"},
    {0x28, "Turn off the light"},
    {0x29, "Cold light turn on"},
    {0x2a, "Cold light turn off"},
    {0x2b, "Warm light turn on"},
    {0x2c, "Warm light turn off"}
};

GroveVoice::GroveVoice() : _serial(&Serial1), _rxPin(-1), _txPin(-1), _wakeWordCode(0x00) {}

bool GroveVoice::begin(int rxPin, int txPin) {
    if (rxPin == -1) rxPin = GROVE_SCL; // GPIO 1 on Cardputer
    if (txPin == -1) txPin = GROVE_SDA; // GPIO 2 on Cardputer
    
    _rxPin = rxPin;
    _txPin = txPin;
    
    _serial->begin(115200, SERIAL_8N1, _rxPin, _txPin);
    return true;
}

void GroveVoice::end() {
    _serial->end();
}

int GroveVoice::available() {
    return _serial->available();
}

uint8_t GroveVoice::readCommand() {
    // Protocol: 0x5a [CMD] 0x0 0x0 [CHECKSUM]
    // Checksum = 0x5a + [CMD] + 0x0 + 0x0
    if (_serial->available() >= 5) {
        uint8_t header = _serial->read();
        if (header == 0x5a) {
            uint8_t cmd = _serial->read();
            uint8_t dummy1 = _serial->read();
            uint8_t dummy2 = _serial->read();
            uint8_t checksum = _serial->read();
            
            if (checksum == (uint8_t)(header + cmd + dummy1 + dummy2)) {
                return cmd;
            }
        }
    }
    return 0xFF; // No valid command
}

const char* GroveVoice::getCommandText(uint8_t cmd) {
    // Check for alias first
    for (const auto& vc : _aliases) {
        if (vc.cmd == cmd) {
            return vc.text;
        }
    }
    // Then check default commands
    for (const auto& vc : defaultVoiceCommands) {
        if (vc.cmd == cmd) {
            return vc.text;
        }
    }
    return "Unknown Command";
}

void GroveVoice::addAlias(uint8_t cmd, const char* text) {
    _aliases.push_back({cmd, text});
}

void GroveVoice::clearAliases() {
    _aliases.clear();
}

void GroveVoice::setWakeWordCode(uint8_t cmd) {
    _wakeWordCode = cmd;
}

uint8_t GroveVoice::getWakeWordCode() const {
    return _wakeWordCode;
}

GroveVoice groveVoice;
