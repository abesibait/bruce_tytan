#include "core/bus_HAL.h"
#include "core/powerSave.h"
#include <interface.h>

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
    // bruceConfig.startupApp = "WebUI";

    setSysI2CBus(&Wire);
    Wire.setPins(SYS_I2C_SDA, SYS_I2C_SCL);
    Wire.begin(SYS_I2C_SDA, SYS_I2C_SCL);
#ifdef USE_IO_EXPANDER
    ioExpander.begin();
#endif

    pinMode(CC1101_SS_PIN, OUTPUT);
    pinMode(NRF24_SS_PIN, OUTPUT);
    pinMode(SS, OUTPUT);
    digitalWrite(CC1101_SS_PIN, HIGH);
    digitalWrite(NRF24_SS_PIN, HIGH);
    digitalWrite(SS, HIGH);

    pinMode(TFT_CS, OUTPUT);
    digitalWrite(TFT_CS, HIGH);
    pinMode(SDCARD_CS, OUTPUT);
    digitalWrite(SDCARD_CS, HIGH);

    bruceConfigPins.irRx = RXLED;
    bruceConfigPins.irTx = TXLED;
    bruceConfigPins.rfModule = CC1101_SPI_MODULE;
    // bruceConfigPins.rfidModule = ST25R3916_SPI_MODULE;
}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() { return 0; }

/***************************************************************************************
** Function name: isCharging()
** Description:   Default implementation that returns false
***************************************************************************************/
bool isCharging() { return false; }

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) {}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    static unsigned long tm = 0;
    if (millis() - tm < 200 && !LongPress) return;
    bool _u = ioExpander.readPin(IO_EXP_UP);
    bool _d = ioExpander.readPin(IO_EXP_DOWN);
    bool _l = ioExpander.readPin(IO_EXP_LEFT);
    bool _r = ioExpander.readPin(IO_EXP_RIGHT);
    bool _s = ioExpander.readPin(IO_EXP_SEL);
    bool _e = ioExpander.readPin(IO_EXP_ESC);
    bool _btn1 = ioExpander.readPin(IO_EXP_BTN1);
    bool _btn2 = ioExpander.readPin(IO_EXP_BTN2);

    if (!_s || !_u || !_d || !_r || !_l) {
        tm = millis();
        if (!wakeUpScreen()) AnyKeyPress = true;
        else return;
    }
    if (!_l) { PrevPress = true; }
    if (!_r) { NextPress = true; }
    if (!_u) {
        UpPress = true;
        // PrevPagePress = true;
    }
    if (!_d) {
        DownPress = true;
        // NextPagePress = true;
    }
    if (!_s) { SelPress = true; }
    if (!_e) { EscPress = true; }
    if (!_btn1) { NextPagePress = true; }
    if (!_btn2) { PrevPagePress = true; }
}

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
** Turns off the device (or try to)
**********************************************************************/
void powerOff() {}

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
** Btn logic to turnoff the device (name is odd btw)
**********************************************************************/
void checkReboot() {}
