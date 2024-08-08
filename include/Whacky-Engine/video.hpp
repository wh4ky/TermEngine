/* 
    Check out my Github https://github.com/wh4ky.
    Use this to your liking; no warranty is provided; a shout-out would be greatly appreciated.
*/

#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace WE
{
    class termScreen
    {
        private:
            static char ***video;
            static int y_height;
            static int x_width;

        public:
            static void clear();
            static void setRes(int x, int y);
            static void replace(int x, int y, const char *new_value);
            static void update();
            static void alloc();
            static void deAlloc();

    };
}

#endif // VIDEO_HPP
