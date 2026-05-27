#ifndef COLOUR_SELECTOR_H
#define COLOUR_SELECTOR_H

#include "colour_select.h"
#include "colour_types.h"
#include "lgfx_config.h"
#include <cstdint>

class ColourSelector {
public:
  ColourSelector(LGFX_Config &lcd, uint8_t height = 30);
  void handle_event(lgfx::touch_point_t tp);
  rgb_t get_active_colour();
  void draw();

private:
  LGFX_Config &_lcd;
  uint8_t _height;
  ColourSelect _colours[15];
  uint8_t _colour_count = 15;
  lgfx::LGFX_Sprite _canvas;
  uint8_t _active_colour = 0;
};

#endif
