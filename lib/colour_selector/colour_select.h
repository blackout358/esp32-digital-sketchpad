
#ifndef COLOUR_SELECT_H
#define COLOUR_SELECT_H

#include "colour_types.h"
#include "lgfx_config.h"

class ColourSelect {
public:
  ColourSelect(LGFX_Config &lcd, rgb_t colour, uint8_t index, uint8_t height,
               uint8_t width);
  void draw(lgfx::LGFX_Sprite &canvas);
  void toggle_active();
  rgb_t get_rgb_t();

private:
  rgb_t _colour;
  uint8_t _index;
  uint8_t _height;
  uint8_t _width;
  bool _active;
  LGFX_Config &_lcd;
  lgfx::LGFX_Sprite _canvas;
};

#endif
