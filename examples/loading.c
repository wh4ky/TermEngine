/* 
    Check out my Github https://github.com/wh4ky.
    Use this to your liking; no warranty is provided; please leave this here.
*/

#include <stdbool.h>
#include <unistd.h>

#include "../lib/all.h"

const int WINDOW_WIDTH = 40;
const int WINDOW_HEIGHT = 20;
const int DELAY_MICROSECONDS = 33300; // Approximately 30 FPS

int main(void)
{
    clear();
    setRes(WINDOW_WIDTH, WINDOW_HEIGHT);
    allocScreen();

    bool loop = true;
    int times = 0;
    int loading = 1;
    
    while (loop)
    {
        for (int i = 0; i < WINDOW_WIDTH; i++)
        {
            replace(i, 0, color8BitBack(8));
            replace(i, WINDOW_HEIGHT - 1, color8BitBack(8));
        }

        for (int i = 0; i < WINDOW_HEIGHT; i++)
        {
            replace(0, i, color8BitBack(8));
            replace(WINDOW_WIDTH - 1, i, color8BitBack(8));
        }
        
        if (loading == 1)
        {
            replace(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, color8BitBack(15));
            replace(WINDOW_WIDTH/2 -1, WINDOW_HEIGHT/2, color8BitBack(0));
        }
        else if (loading == 2)
        {
            replace(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 1, color8BitBack(15));
            replace(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, color8BitBack(0));
        }
        else if (loading == 3)
        {
            replace(WINDOW_WIDTH/2 - 1, WINDOW_HEIGHT/2 + 1, color8BitBack(15));
            replace(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 1, color8BitBack(0));
        }
        else if (loading == 4)
        {
            replace(WINDOW_WIDTH/2 -1, WINDOW_HEIGHT/2, color8BitBack(15));
            replace(WINDOW_WIDTH/2 - 1, WINDOW_HEIGHT/2 + 1, color8BitBack(0));
        }
        else {loading = 0;}
        loading++;

        clear();
        updateScreen();

        usleep(DELAY_MICROSECONDS);

        if (times == 100){loop = false;}
        else {++times;}
    }

    deAllocScreen();

    return 0;
}