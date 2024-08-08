/* 
    Check out my Github https://github.com/wh4ky.
    Use this to your liking; no warranty is provided; a shout-out would be greatly appreciated.
*/

#ifndef COLOR_HPP
#define COLOR_HPP

#include <stdio.h>

namespace WE
{
    class color
    {
        protected:
            static constexpr char esc = '\033';
            static constexpr const char* control = "[";

        public:
            class eightBit // colors indexed from 0 to 255 aka 8-bit colors
            {
                private:
                    static constexpr const char* foregroundPrefix = "38;5;";
                    static constexpr const char* backgroundPrefix = "48;5;";
                    static char fullBuffer[24];
                    static char partialBuffer[13];

                public:
                    static char *full(int backgroundColor, int foregroundColor);
                    static char *back(int backgroundColor);
                    static char *fore(int foregroundColor);
            };

            class RGB // Red, Green, Blue
            {
                private:
                    static constexpr const char* foregroundPrefix = "38;2;";
                    static constexpr const char* backgroundPrefix = "48;2;";
                    static char fullBuffer[40];
                    static char partialBuffer[16];

                public:
                    static char *full(int backgroundRed, int backgroundGreen, int backgroundBlue, int foregroundRed, int foregroundGreen, int foregroundBlue);
                    static char *back(int red, int green, int blue);
                    static char *fore(int red, int green, int blue);
            };

            class CMY // Cyan, Magenta, Yellow
            {
                private:
                    static constexpr const char* foregroundPrefix = "38;4;";
                    static constexpr const char* backgroundPrefix = "48;4;";
                    static char fullBuffer[40];
                    static char partialBuffer[16];

                public:
                    static char *full(int backgroundCyan, int backgroundMagenta, int backgroundYellow, int foregroundCyan, int foregroundMagenta, int foregroundYellow);
                    static char *back(int cyan, int magenta, int yellow);
                    static char *fore(int cyan, int magenta, int yellow);
            };
    };
}

#endif // COLOR_HPP