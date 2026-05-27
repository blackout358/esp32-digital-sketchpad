#ifndef PINS_H
#define PINS_H

// --- Display Pins (SPI2_HOST) ---
#define TFT_SCLK 3
#define TFT_MOSI 45
#define TFT_MISO 46
#define TFT_DC 47
#define TFT_CS 14
#define TFT_RST 21
#define TFT_BL 9

// --- Touch Pins (SPI3_HOST) ---
#define TOUCH_SCLK 42 // TCLK
#define TOUCH_MOSI 2  // TDIN
#define TOUCH_MISO 41 // TDO
#define TOUCH_CS 1    // TCS

#endif
