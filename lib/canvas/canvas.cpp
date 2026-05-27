#include "canvas.h"

Canvas::Canvas(LGFX_Config &lcd, uint16_t height) : _lcd(lcd), _canvas(&lcd) {
  _canvas.createSprite(240, height);
  _canvas.fillSprite(0xFFFF);
  _height = height;
}

void Canvas::draw() { _canvas.pushSprite(0, 0); }

void Canvas::handle_event(lgfx::touch_point_t tp, rgb_t colour) {

  int x = tp.x - (BRUSH_SIZE / 5);
  int y = tp.y - (BRUSH_SIZE / 5);
  _canvas.fillCircle(x, y, BRUSH_SIZE, colour.to_565());
}
