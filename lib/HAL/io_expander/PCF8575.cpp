#include "PCF8575.h"

PCF8575::PCF8575() {}
PCF8575::~PCF8575() {}

bool PCF8575::begin(uint8_t address, TwoWire *wire) {
    _i2caddr = address;
    _wire = wire;

    // Power-on-reset default on the PCF8575 is all pins HIGH (all inputs).
    // Read the current word so we start from the chip's actual state
    // rather than assuming - matches how PCA9555::begin() reads back
    // its registers instead of blindly writing zeros.
    uint16_t word = 0;
    if (!readWord(word)) return false;

    port_state = word;
    return true;
}

void PCF8575::pinMode(uint8_t pin, uint8_t mode) {
    if (pin > 15) return;

    if (mode == INPUT || mode == INPUT_PULLUP) {
        // "Input" on the PCF8575 = drive the bit HIGH so the pin floats
        // to its weak internal pull-up and can be pulled low externally.
        port_state |= (1 << pin);
    } else { // OUTPUT
        // Default newly-configured outputs LOW until digitalWrite() sets
        // them explicitly - avoids accidentally energizing something.
        port_state &= ~(1 << pin);
    }

    writeWord(port_state);
}

void PCF8575::digitalWrite(uint8_t pin, bool val) {
    if (pin > 15) return;

    if (val) port_state |= (1 << pin);
    else     port_state &= ~(1 << pin);

    writeWord(port_state);
}

bool PCF8575::digitalRead(uint8_t pin) {
    if (pin > 15) return false;

    uint16_t word = 0;
    if (!readWord(word)) return false;

    return (word >> pin) & 0x1;
}

bool PCF8575::writeWord(uint16_t word) {
    _wire->beginTransmission(_i2caddr);
    _wire->write(static_cast<uint8_t>(word & 0xFF));        // low byte (P0)
    _wire->write(static_cast<uint8_t>((word >> 8) & 0xFF)); // high byte (P1)
    return (_wire->endTransmission() == 0);
}

bool PCF8575::readWord(uint16_t &word) {
    if (_wire->requestFrom(static_cast<int>(_i2caddr), 2) != 2) return false;

    uint8_t low  = _wire->read();
    uint8_t high = _wire->read();
    word = (static_cast<uint16_t>(high) << 8) | low;
    return true;
}
