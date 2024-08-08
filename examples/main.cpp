#include "../include/Whacky-Engine/color.hpp"

#include <iostream>

int main() {
    std::cout << WE::color::getEscapeCode24bit::full(155, 155, 155, 255, 0, 0, 'X');
}