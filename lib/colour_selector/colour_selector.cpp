#include "colour_selector.h"
#include "colour_select.h"
#include "colour_types.h"

ColourSelector::ColourSelector(LGFX_Config &lcd, uint8_t height)
    : _lcd(lcd), _canvas(&lcd),
      _colours{
          {lcd, {0, 0, 0}, 0, height, 16},       // 0: Black
          {lcd, {255, 0, 0}, 1, height, 16},     // 1: Red
          {lcd, {255, 64, 0}, 2, height, 16},    // 2: Orange-Red
          {lcd, {255, 128, 0}, 3, height, 16},   // 3: Orange
          {lcd, {255, 192, 0}, 4, height, 16},   // 4: Amber
          {lcd, {255, 255, 0}, 5, height, 16},   // 5: Yellow
          {lcd, {128, 255, 0}, 6, height, 16},   // 6: Lime
          {lcd, {0, 255, 0}, 7, height, 16},     // 7: Green
          {lcd, {0, 255, 128}, 8, height, 16},   // 8: Spring Green
          {lcd, {0, 255, 255}, 9, height, 16},   // 9: Cyan
          {lcd, {0, 128, 255}, 10, height, 16},  // 10: Azure
          {lcd, {0, 0, 255}, 11, height, 16},    // 11: Blue
          {lcd, {127, 0, 255}, 12, height, 16},  // 12: Violet
          {lcd, {255, 0, 255}, 13, height, 16},  // 13: Magenta
          {lcd, {255, 255, 255}, 14, height, 16} // 14: White
      } {
  _canvas.createSprite(240, height);
  _height = height;
  _active_colour = 0;
  _colours[0].toggle_active();
}

void ColourSelector::handle_event(lgfx::touch_point_t tp) {
  int16_t x = tp.x;
  uint8_t colour_index = (uint8_t)x / (_colour_count + 1);

  if (colour_index == _active_colour) {
    return;
  }
  _colours[_active_colour].toggle_active();
  _colours[colour_index].toggle_active();
  _active_colour = colour_index;
}

void ColourSelector::draw() {
  for (int i = 0; i < 15; i++) {
    _colours[i].draw(_canvas);
  }
  _canvas.pushSprite(0, HEIGHT - _height);
}

rgb_t ColourSelector::get_active_colour() {
  return _colours[_active_colour].get_rgb_t();
}
