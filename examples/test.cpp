// g++ -std=c++17 ./examples/main.cpp -L./out -lstatTermEngine_0.0.0

#include <iostream>
#include <unistd.h>
#include <termios.h>

void enableMouseReporting()
{
    std::cout << "\033[?1003h";
    std::cout.flush();
}

void disableMouseReporting()
{
    std::cout << "\033[?1003l";
    std::cout.flush();
}

struct termios orig_termios;

void restoreSettings()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
    disableMouseReporting();
}

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(restoreSettings);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();
    enableMouseReporting();

    char buf[32];

    std::cout << "Mouse reporting enabled. Move the mouse or click to see events.\n";

    while (true) {
        int bytesRead = read(STDIN_FILENO, buf, sizeof(buf) - 1);

        if (bytesRead > 0) {
            buf[bytesRead] = '\0';

            std::cout << "Raw input: ";
            for (int i = 0; i < bytesRead; ++i) {
                std::cout << std::dec << std::uppercase << (int)(unsigned char)buf[i] << " ";
            }
            std::cout << std::dec << std::endl;
            std::cout.flush(); 
        }
        usleep(1000);
    }
    return 0;
}
