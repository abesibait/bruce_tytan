#ifndef _PCF8575_H
#define _PCF8575_H

#include <Arduino.h>
#include <Wire.h>

#define PCF8575_DEFAULT_ADDR 0x20

class PCF8575 {
public:
    PCF8575();
    ~PCF8575();

    bool begin(uint8_t address = PCF8575_DEFAULT_ADDR, TwoWire *wire = &Wire);

    void pinMode(uint8_t pin, uint8_t mode);
    void digitalWrite(uint8_t pin, bool val);
    bool digitalRead(uint8_t pin);

private:
    TwoWire *_wire;
    uint8_t  _i2caddr;

    // PCF8575 has no real direction register - "input" just means the bit
    // is held HIGH (weak pull-up), "output" means we actively drive it.
    // We track the last written 16-bit word state so we only ever change
    // the one bit we're asked to change, never clobbering the other 15.
    uint16_t port_state;

    bool writeWord(uint16_t word);
    bool readWord(uint16_t &word);
};

#endif // _PCF8575_H
