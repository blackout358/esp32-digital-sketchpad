
#include "canvas.h"
#include "colour_selector.h"
#include "colour_types.h"
#include "lgfx/v1/Touch.hpp"
#include "lgfx_config.h"
#include "sample.h"
#include <optional>

#define PALLET_HEIGHT 30
#define CANVAS_HEIGHT 290

LGFX_Config lcd;

ColourSelector colour_selector = ColourSelector(lcd, PALLET_HEIGHT);
Canvas canvas = Canvas(lcd, CANVAS_HEIGHT);

uint16_t cal_data[8] = {226, 3811, 288, 193, 3891, 3826, 3900, 182};

std::optional<lgfx::touch_point_t> check_touch_event() {
  lgfx::touch_point_t tp;
  if (lcd.getTouch(&tp)) {
    return std::make_optional<lgfx::touch_point_t>(tp);
  }
  return std::nullopt;
}

void draw() {
  colour_selector.draw();
  canvas.draw();
}

void setup() {

  lcd.init();
  lcd.setRotation(2);

  lcd.setTouchCalibrate(cal_data);

  draw();
}

void loop() {
  std::optional<lgfx::touch_point_t> touch = check_touch_event();
  if (touch) {
    auto tp = touch.value();
    auto y = tp.y;
    if (y < CANVAS_HEIGHT) {
      canvas.handle_event(tp, colour_selector.get_active_colour());
    } else {
      colour_selector.handle_event(tp);
    }
    draw();
  }
}
