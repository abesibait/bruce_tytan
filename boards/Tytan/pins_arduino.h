#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001
#define USB_as_HID 1

// // Some boards have too low voltage on this pin (board design bug)
// // Use different pin with 3V and connect with 48
// // and change this setup for the chosen pin (for example 38)
// #define PIN_RGB_LED 48
// // BUILTIN_LED can be used in new Arduino API digitalWrite() like in Blink.ino
// static const uint8_t LED_BUILTIN = SOC_GPIO_PIN_COUNT + PIN_RGB_LED;
// #define BUILTIN_LED LED_BUILTIN // backward compatibility
// #define LED_BUILTIN LED_BUILTIN // allow testing #ifdef LED_BUILTIN
// // RGB_BUILTIN and RGB_BRIGHTNESS can be used in new Arduino API rgbLedWrite()
// #define RGB_BUILTIN LED_BUILTIN
// #define RGB_BRIGHTNESS 64

#define HAS_RGB_LED 1
#define LED_ORDER GRB
#define LED_TYPE_IS_RGBW 1
#define LED_COUNT 1
#define LED_TYPE WS2812
#define LED_COLOR_STEP 15
#define RGB_LED 48

#define GROVE_SDA 11
#define GROVE_SCL 10
#define SYS_I2C_SDA 11
#define SYS_I2C_SCL 10

#define SPI_SCK_PIN 12
#define SPI_MOSI_PIN 14
#define SPI_MISO_PIN 13
#define SPI_SS_PIN 47

static const uint8_t TX = 1;
static const uint8_t RX = 2;

static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;

static const uint8_t SS = SPI_SS_PIN;
static const uint8_t MOSI = SPI_MOSI_PIN;
static const uint8_t MISO = SPI_MISO_PIN;
static const uint8_t SCK = SPI_SCK_PIN;

#define RXLED 4
#define TXLED 5
#define LED_ON HIGH
#define LED_OFF LOW

#define USE_CC1101_VIA_SPI
#define CC1101_GDO0_PIN 39
#define CC1101_GDO2_PIN 41
#define CC1101_SS_PIN 40
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN 21
#define NRF24_SS_PIN 38
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN 21
#define NRF24_SS_PIN 38
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

#define USE_W5500_VIA_SPI
#define W5500_SS_PIN 6
#define W5500_MOSI_PIN SPI_MOSI_PIN
#define W5500_SCK_PIN SPI_SCK_PIN
#define W5500_MISO_PIN SPI_MISO_PIN
// #define W5500_INT_PIN 6

#define FP 1
#define FM 2
#define FG 3

#define HAS_SCREEN 1
#define ROTATION 1
#define MINBRIGHT (uint8_t)1

#define USER_SETUP_LOADED 1
#define ST7789_DRIVER 1
#define TFT_RGB_ORDER 0
#define TFT_WIDTH 240
#define TFT_HEIGHT 280
#define TFT_BACKLIGHT_ON 1
#define TFT_BL -1
#define TFT_RST 16
#define TFT_DC 15
#define TFT_MISO 8
#define TFT_MOSI 17
#define TFT_SCLK 18
#define TFT_CS 7
#define TOUCH_CS -1 // SDCARD_CS to make sure SDCard works
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 20000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000

#define SDCARD_CS 3
#define SDCARD_SCK 18
#define SDCARD_MISO 8
#define SDCARD_MOSI 17

#define BTN_ALIAS "\"OK\""
#define HAS_5_BUTTONS
// #define SEL_BTN 0
// #define UP_BTN 41
// #define DW_BTN 40
// #define R_BTN 38
// #define L_BTN 39
#define BTN_ACT LOW

// IO EXPANDER
#define USE_IO_EXPANDER
#define IO_EXPANDER_PCF8575
#define P00 0
#define P01 1
#define P02 2
#define P08 8
#define P09 9
#define P10 10
#define P11 11
#define P12 12

#define IO_EXP_UP P08    // physical UP button
#define IO_EXP_DOWN P09  // physical DOWN button
#define IO_EXP_ESC P02   // physical BACK button
#define IO_EXP_LEFT P12  // physical LEFT button
#define IO_EXP_RIGHT P11 // physical RIGHT button
#define IO_EXP_SEL P10   // physical SELECT button
#define IO_EXP_BTN1 P01  // extra button 1
#define IO_EXP_BTN2 P00  // extra button 2
#endif                   /* Pins_Arduino_h */
