
#include "colour_select.h"

ColourSelect::ColourSelect(LGFX_Config &lcd, rgb_t colour, uint8_t index,
                           uint8_t height, uint8_t width)
    : _lcd(lcd), _canvas(&lcd) {
  _canvas.createSprite(width, height);
  _canvas.fillSprite(colour.to_565());
  _colour = colour;
  _index = index;
  _height = height;
  _width = width;
  _active = false;
}
void ColourSelect::draw(lgfx::LGFX_Sprite &canvas) {
  int xpos = _index * _width;
  int ypos = 0;
  _canvas.pushSprite(&canvas, xpos, 0);
  if (_active) {
    canvas.drawRect(xpos, ypos, _width, _height, TFT_GRAY);
    canvas.drawRect(xpos + 1, ypos + 1, _width - 2, _height - 2, TFT_GRAY);
  }
}

rgb_t ColourSelect::get_rgb_t() { return _colour; }

void ColourSelect::toggle_active() { _active = !_active; }
