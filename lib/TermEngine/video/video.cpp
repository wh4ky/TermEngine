/*
  Check out my Github https://github.com/wh4ky.
  Use this to your liking; no warranty is provided; a shout-out would be greatly appreciated.
*/

#include "TermEngine/video/video.hpp"

std::vector<std::vector<std::string>> *TE::termScreen::video = nullptr;
int TE::termScreen::y_height = 0;
int TE::termScreen::x_width = 0;

void TE::termScreen::clear() { printf("\033[0;0H\033[0J"); }

void TE::termScreen::setRes(int x, int y) {
  x_width = x;
  y_height = y;
}

void TE::termScreen::cellSet(int x, int y, std::string new_value) {
  (*video)[y][x] = new_value;

  // throw std::runtime_error("Error in \"TE::termScreen::cellSet\": could not
  // replace old cell with new value.");
}

/*void TE::termScreen::termSet(char ***&preSetVideo) {
  for (int i = 0; i < y_height; i++) {
    video[i] = preSetVideo[i];

    for (int j = 0; j < x_width; j++) {
      video[i][j] = preSetVideo[i][j];
    }
  }
}*/

void TE::termScreen::update() {
  for (int i = 0; i < y_height; i++) {
    for (int j = 0; j < x_width; j++) {
      printf("%s", (*video)[i][j].c_str());
      if (j == x_width - 1) {
        printf("\n");
      }
    }
  }
  printf("\n");
}

void TE::termScreen::fill() {
  for (int i = 0; i < y_height; i++) {
    for (int j = 0; j < x_width; j++) {
      (*video)[i][j] = ".";
    }
  }
}

void TE::termScreen::alloc() {
  video = new std::vector<std::vector<std::string>>(
      x_width, std::vector<std::string>(y_height));
}

void TE::termScreen::deAlloc() { delete video; }
