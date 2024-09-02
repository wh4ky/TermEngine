# Whacky Engine

## Contents

- [About](#about)
- [Future Development](#future-development)
- [Installing And Using](#installing-and-using)

## About

TermEngine (TE for short) is an engine which allows you to do stuff on the terminal with [ASCII](https://en.wikipedia.org/wiki/ASCII) and [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code).

## Future Development

- Something I won't abandon.
- Make shape-making easier.
- More optimized rendering of the screen.
- Support for use in other languages.

## Installing And Using

### Prerequisites

- Cmake
- Gcc/G++

### Installing

Instalation guide for Linux.

- [Download](https://github.com/wh4ky/TermEngine/archive/refs/heads/main.zip) the source code.
- Unzip
- Go into the root directory of the program (in your terminal).
- And type the beneath commands into your terminal.

```sh
mkdir ./build
cd build
cmake ..
make
```

### Using

- Include the .hpp files you want to use in your program.
- The library files should be in the /out directory.
- To compile your program run: `G++ your_program.cpp path/to/TermEngine_x.x.x.x`
- Read the [documentation](./docs/DOCS.md).
