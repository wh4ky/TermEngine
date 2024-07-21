/* 
    Check out my Github https://github.com/wh4ky.
    Use this to your liking; no warranty is provided; please leave this here.
*/

#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>

char *color8BitFore(int x)
{
    static char buffer[16];
    sprintf(buffer, " \033[38;5;%dm", x);
    return buffer;
}

char *color8BitBack(int x)
{
    static char buffer[16];
    sprintf(buffer, " \033[48;5;%dm", x);
    return buffer;
}

char *color24BitFore(int r, int g, int b)
{
    static char buffer[32];
    sprintf(buffer, " \033[38;2;%d;%d;%dm", r, g, b);
    return buffer;
}

char *color24BitBack(int r, int g, int b)
{
    static char buffer[32];
    sprintf(buffer, " \033[48;2;%d;%d;%dm", r, g, b);
    return buffer;
}

#endif