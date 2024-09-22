// TEST do not use

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <signal.h>
#include <string>
#include <tuple>

namespace TE
{
    class IO
    {
    private:
        static struct termios original;

        static void signalHandle(int signum)
        {
        revertTerminal();
        disableMouseReporting();
        exit(0);
        }

        static void disableMouseReporting()
        {
            std::cout << "\033[?1003l";
            std::cout.flush();
            std::cout << "\033[?1006l";
            std::cout.flush();
        }

        static void enableMouseReporting()
        {
            std::cout << "\033[?1003h";
            std::cout.flush();
            std::cout << "\033[?1006h";
            std::cout.flush();
        }

        static void revertTerminal()
        {
            tcsetattr(STDIN_FILENO, TCSANOW, &original);
        }

    public:
        IO()
        {
            signal(SIGINT, signalHandle);

            std::cout << "\033[?1003h";
            std::cout.flush();
            std::cout << "\033[?1006h";
            std::cout.flush();

            tcgetattr(STDIN_FILENO, &original);
            struct termios raw = original;
            raw.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
        }

        ~IO()
        {
            revertTerminal();
            disableMouseReporting();
        }

        void revertSettings()
        {
            revertTerminal();
            disableMouseReporting();
        }

        std::string getKey() // function to get single keys (To Do: F-row and other keys)
        {
            disableMouseReporting();
            char buf[10];
            int bytesRead = read(STDIN_FILENO, buf, sizeof(buf) - 1);
            buf[bytesRead] = '\0';

            std::string str(buf);

            std::cout << str << " control" << std::endl;
            
            std::string out;
            
            

            return out;
        }
    };

    /*  Function to get mouse clicks
    std::tuple getMouse()
        {
            char buf[32];
            int bytesRead = read(STDIN_FILENO, buf, sizeof(buf) - 1);

            if (bytesRead <= 1)
            {
                buf[bytesRead] = '\0';

                for (int i = 0; i < bytesRead; ++i) {
                    printf("%c ", buf[i]);
                }
                std::cout.flush(); 

                std::string str(buf);
                return str;
            }
            return "null";
        }
    };
    */

    struct termios IO::original;
}

int main()
{
    TE::IO io;

    while (true)
    {
        if (io.getKey() == "q")
        {
            io.revertSettings();
            return 0;
        }
        
        else if (io.getKey() != "null")
        {
            std::cout << io.getKey() << std::endl;
        }

        usleep(1000);
    }

    io.revertSettings();
    return 0;
}
