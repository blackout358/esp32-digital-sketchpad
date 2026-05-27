
#ifndef CANVAS_H
#define CANVAS_H

#include "colour_types.h"
#include "lgfx_config.h"
#include <cstdint>

#define BRUSH_SIZE 5

class Canvas {
public:
  Canvas(LGFX_Config &lcd, uint16_t);
  void handle_event(lgfx::touch_point_t tp, rgb_t colour);
  void draw();

private:
  LGFX_Config &_lcd;
  lgfx::LGFX_Sprite _canvas;
  uint16_t _height;
};

#endif
