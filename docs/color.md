# color.hpp

Help with colors can be found [here](https://en.wikipedia.org/wiki/ANSI_escape_code#Colors).

## `char *color8BitFore(int x)`

Returns ANSI code for a 8-bit foreground color.  
`x` can range from 0 to 255.  

## `char *color8BitBack(int x)`

Returns ANSI code for a 8-bit background color.  
`x` can range from 0 to 255.  

## `char *color24BitFore(int r, int g, int b)`

Returns ANSI code for a 24-bit foreground color.  
`r`, `g` and `b` can range from 0 to 255.  

## `char *color24BitBack(int r, int g, int b)`

Returns ANSI code for a 24-bit background color.  
`r`, `g` and `b` can range from 0 to 255.  
