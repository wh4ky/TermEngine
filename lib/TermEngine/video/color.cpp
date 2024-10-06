/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly appreciated.
*/

#include "TermEngine/video/color.hpp"

char TE::color::eightBitBuffer[13] = {0};
char TE::color::rgbBuffer[21] = {0};

char *TE::color::background(unsigned int color) { // 8-bit
  sprintf(eightBitBuffer, "%s%s%s%o%s",
          esc, foregroundPrefix, eightBitPrefix, color, end);
  return eightBitBuffer;
}

char *TE::color::foreground(unsigned int color) { // 8-bit
  sprintf(eightBitBuffer, "%s%s%s%o%s",
          esc, backgroundPrefix, eightBitPrefix, color, end);
  return eightBitBuffer;
}

char *TE::color::background(unsigned int red, unsigned int green, unsigned int blue) { // rgb
  sprintf(rgbBuffer, "%s%s%s%o%c%o%c%o%s",
          esc, foregroundPrefix, rgbPrefix, red, semicolon, green, semicolon, blue, end);
  return rgbBuffer;
}

char *TE::color::foreground(unsigned int red, unsigned int green, unsigned int blue) { // rgb
  sprintf(rgbBuffer, "%s%s%s%o%c%o%c%o%s",
          esc, backgroundPrefix, rgbPrefix, red, semicolon, green, semicolon, blue, end);
  return rgbBuffer;
}