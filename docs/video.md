# video.h

## `void  clear()`

Prints the `\033[0;0H\033[0J` character to the console, which clears the terminal.  

## `void  setRes(int  x, int  y)`

Sets the canvas width `x` and height `y`.  

## `void  updateScreen()`

Prints the canvas.  
Use `clear()` before printing the canvas.  

## `void replace(int x, int y, const char *new_value)`

Replaces the value on canvas `x` and `y` coordinates with `new_value`.  
`new_value` should be an ANSI code.  

## `void allocScreen()`

Allocates heap memory for the canvas.  

## `void  deAllocScreen()`

De-allocates heap memory for the canvas.  
Use at the end of the program, when you want to change the resolution or you want to allocate the canvas again.  
