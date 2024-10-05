/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly appreciated.
*/

#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <new>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

namespace TE {
class termScreen {
private:
  static std::vector<std::vector<std::string>> *video;
  static int y_height;
  static int x_width;

public:
  static void clear();
  static void setRes(int x, int y);
  static void cellSet(int x, int y, std::string new_value);
  // static void termSet(char ***&preSetVideo);
  static void update();
  static void fill();
  static void alloc();
  static void deAlloc();
};
} // namespace TE

#endif // VIDEO_HPP
