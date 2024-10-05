/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly appreciated.
*/

#ifndef COLOR_HPP
#define COLOR_HPP

#include <stdio.h>

namespace TE {
class color {
protected:
  static constexpr const char esc = '\033[';
  static constexpr const char semicolon = ';';
  static constexpr const char *foregroundPrefix = "38;";
  static constexpr const char *backgroundPrefix = "48;";
  static constexpr const char *eightBitPrefix = "5;";
  static constexpr const char *rgbPrefix = "2;";
  static constexpr const char end = 'm';
  static char eightBitBuffer[13];
  static char rgbBuffer[21];

public:
  static char *background(unsigned int color);
  static char *foreground(unsigned int color);
  static char *background(unsigned int red, unsigned int green, unsigned int blue);
  static char *foreground(unsigned int red, unsigned int green, unsigned int blue);
};
} // namespace TE

#endif // COLOR_HPP