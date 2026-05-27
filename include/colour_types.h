#ifndef COLOUR_TYPES_H
#define COLOUR_TYPES_H

#include <cstdint>

#define BLUE rgb_t(0, 0, 255)

struct rgb_t {
  uint8_t r;
  uint8_t g;
  uint8_t b;

  rgb_t() : r(0), g(0), b(0) {}
  rgb_t(uint8_t red, uint8_t green, uint8_t blue) : r(red), g(green), b(blue) {}

  uint16_t to_565() const {
    return static_cast<uint16_t>(((r & 0xF8) << 8) | ((g & 0xFC) << 3) |
                                 (b >> 3));
  }
  uint32_t to_hex() const { return (r << 16) | (g << 8) | b; }
};

#endif
