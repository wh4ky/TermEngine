# Whacky Engine

## Contents

- [About](#about)
- [Soon™](#soon)
- [Aim Of The Game](#aim-of-the-game)
- [Installing And Using](#installing-and-using)

## About

TermEngine (TE for short) is an engine which allows you to display and maybe make games in the terminal with [ASCII](https://en.wikipedia.org/wiki/ASCII) and [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code).

## Soon™

- Something I won't abandon.
- GameObjects (objects that contain all data needed for displaying, moving, ect.)
- 3D rendering with OpenCL.
- Lua bindings.

## Aim Of The Game

I want TE to be fully compatible with the TTY on unix systems.  

## Installing And Using

### Prerequisites

- Cmake
- Gcc/G++

### Installing

Installation guide for most Unix systems:

- Download the source code zip file.
- Unzip the file.
- Go into the root directory of the program (in your terminal).
- And type these commands into your terminal.

```sh
cd build
cmake ..
make
```

These commands only compile the library statically; go to the root CMakeLists.txt for additional configuration options.

### Using

- Include the .hpp files you want to use in your program.
- The library files should be in the /out directory.
- To compile your program run: `G++ your_program.cpp path/to/libTermEngine_x.x.x.x`
- Read the [documentation](./docs/DOCS.md).
