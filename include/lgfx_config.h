#ifndef LGFX_CONFIG_H
#define LGFX_CONFIG_H

#include "pins.h"
#include <LovyanGFX.hpp>

#define HEIGHT 320
#define WIDTH 240

class LGFX_Config : public lgfx::LGFX_Device {
  lgfx::Panel_ILI9341 _panel_instance;
  lgfx::Bus_SPI _bus_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Touch_XPT2046 _touch_instance;

public:
  LGFX_Config() {
    { // 1. DISPLAY BUS
      auto cfg = _bus_instance.config();
      cfg.spi_host = SPI2_HOST;
      cfg.pin_sclk = TFT_SCLK;
      cfg.pin_mosi = TFT_MOSI;
      cfg.pin_miso = TFT_MISO;
      cfg.pin_dc = TFT_DC;
      cfg.freq_write = 80000000; // 80MHz
      cfg.freq_read = 16000000;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    { // 2. DISPLAY PANEL
      auto cfg = _panel_instance.config();
      cfg.pin_cs = TFT_CS;
      cfg.pin_rst = TFT_RST;
      cfg.memory_width = 240;
      cfg.memory_height = 320;
      cfg.panel_width = WIDTH;
      cfg.panel_height = HEIGHT;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.rgb_order = false;
      cfg.offset_rotation = 0;
      _panel_instance.config(cfg);
    }

    { // 3. TOUCH DEVICE (On SPI3_HOST)
      auto cfg = _touch_instance.config();

      cfg.spi_host = SPI3_HOST;
      cfg.bus_shared = false;

      cfg.pin_sclk = TOUCH_SCLK; // TCLK
      cfg.pin_mosi = TOUCH_MOSI; // TDIN
      cfg.pin_miso = TOUCH_MISO; // TDO
      cfg.pin_cs = TOUCH_CS;     // TCS

      cfg.freq = 1000000; // 1MHz

      cfg.x_min = 0;
      cfg.x_max = 239;
      cfg.y_min = 0;
      cfg.y_max = 319;

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance);
    }

    { // 4. BACKLIGHT
      auto cfg = _light_instance.config();
      cfg.pin_bl = TFT_BL;
      cfg.invert = false;
      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);
    }
    setPanel(&_panel_instance);
  }
};

#endif
