/* 
    Check out my Github https://github.com/wh4ky.
    Use this to your liking; no warranty is provided; a shout-out would be greatly appreciated.
*/

#include "TermEngine/video/color.hpp"

char TE::color::eightBit::fullBuffer[24] = {0};
char TE::color::eightBit::partialBuffer[13] = {0};

char TE::color::RGB::fullBuffer[40] = {0};
char TE::color::RGB::partialBuffer[16] = {0};

char TE::color::CMY::fullBuffer[40] = {0};
char TE::color::CMY::partialBuffer[16] = {0};

char* TE::color::eightBit::full(int backgroundColor, int foregroundColor)
{
    sprintf(fullBuffer, "%c%s%s%dm%c%s%s%dm", esc, control, foregroundPrefix, foregroundColor, esc, control, backgroundPrefix, backgroundColor);
    return fullBuffer;
}

char *TE::color::eightBit::back(int backgroundColor)
{
    sprintf(partialBuffer, "%c%s%s%dm", esc, control, foregroundPrefix, backgroundColor);
    return partialBuffer;
}

char *TE::color::eightBit::fore(int foregroundColor)
{
    sprintf(partialBuffer, "%c%s%s%dm", esc, control, foregroundPrefix, foregroundColor);
    return partialBuffer;
}

char *TE::color::RGB::full(int backgroundRed, int backgroundGreen, int backgroundBlue, int foregroundRed, int foregroundGreen, int foregroundBlue)
{
    sprintf(fullBuffer, "%c%s%s%d;%d;%dm%c%s%s%d;%d;%dm", esc, control, backgroundPrefix, backgroundRed, backgroundGreen, backgroundBlue, esc, control, foregroundPrefix, foregroundRed, foregroundGreen, foregroundBlue);
    return fullBuffer;
}

char *TE::color::RGB::back(int red, int green, int blue)
{
    sprintf(partialBuffer, "%c%s%s%d;%d;%dm", esc, control, backgroundPrefix, red, green, blue);
    return partialBuffer;
}

char *TE::color::RGB::fore(int red, int green, int blue)
{
    sprintf(partialBuffer, "%c%s%s%d;%d;%dm", esc, control, foregroundPrefix, red, green, blue);
    return partialBuffer;
}

char *TE::color::CMY::full(int backgroundCyan, int backgroundMagenta, int backgroundYellow, int foregroundCyan, int foregroundMagenta, int foregroundYellow)
{
    sprintf(fullBuffer, "%c%s%s%d;%d;%dm%c%s%s%d;%d;%dm", esc, control, backgroundPrefix, backgroundCyan, backgroundMagenta, backgroundYellow, esc, control, foregroundPrefix, foregroundCyan, foregroundMagenta, foregroundYellow);
    return fullBuffer;
}

char *TE::color::CMY::back(int cyan, int magenta, int yellow)
{
    sprintf(partialBuffer, "%c%s%s%d;%d;%dm", esc, control, backgroundPrefix, cyan, magenta, yellow);
    return partialBuffer;
}

char *TE::color::CMY::fore(int cyan, int magenta, int yellow)
{
    sprintf(partialBuffer, "%c%s%s%d;%d;%dm", esc, control, foregroundPrefix, cyan, magenta, yellow);
    return partialBuffer;
}