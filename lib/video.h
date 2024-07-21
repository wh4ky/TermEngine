/* 
    Check out my Github https://github.com/wh4ky.
    Use this to your liking; no warranty is provided; please leave this here.
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char ***video;
int x_width;
int y_height;

void clear()
{
    printf("\033[0;0H\033[0J");
}

void setRes(int x, int y)
{
    x_width = x; y_height = y;
}

void allocScreen()
{
    video = (char***)calloc(y_height, sizeof(char**));

    for (int i = 0; i < y_height; i++)
    {
        video[i] = (char**) calloc(x_width, sizeof(char*));

        for (int j = 0; j < x_width; j++)
        {
            video[i][j] = (char*) calloc(strlen(" \033[48;5;0m") + 1, sizeof(char));
            strcpy(video[i][j], " \033[48;5;0m");
        } 
    }

}

void replace(int x, int y, const char *new_value)
{
    size_t new_value_len = strlen(new_value);
    size_t old_value_len = strlen(video[y][x]);

    if (new_value_len == old_value_len && strcmp(video[y][x], new_value) == 0)
    {
        return;
    }

    if (new_value_len <= old_value_len)
    {
        strcpy(video[y][x], new_value);
    }

    else
    {
        free(video[y][x]);
        video[y][x] = (char*)malloc((new_value_len + 1) * sizeof(char));
        strcpy(video[y][x], new_value);
    }

}

void updateScreen()
{
    for (int i = 0; i < y_height; i++)
    { 
        for (int j = 0; j < x_width; j++)
        { 
            printf("%s", video[i][j]);
            if (j == 0) {printf("\n");}
        } 
    }

    printf("\n");
}

void deAllocScreen()
{
    for (int i = 0; i < y_height; i++)
    {
        for (int j = 0; j < x_width; j++)
        {
            free(video[i][j]);
        }
        free(video[i]);
    }
    free(video);
}

#endif