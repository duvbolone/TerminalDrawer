#include "headers/tools.h"
#include "headers/csvparser.h"

int main(int argc, char **argv)
{
    if (containsArg(argc, argv, "--no-start"))
    {
        std::cout << "\t\033[32mStarting...\033[0m" << std::endl;
        usleep(1000000);
    } 
    else 
    {
        std::string bars = repeat("=", (getWindowSize()[0]/2) - 8);
        std::cout << "\033[36m" + bars + "||\033[31mScreenDrawer\033[36m||" + bars + "\033[0m" << std::endl;
        std::cout << "\t Welcome to \033[1mScreenDrawer\033[0m" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "\t Would you like to start the draw process? \033[93m(this will clear the terminal!)\033[0m (Y/N)";

        char startDrawer;
        std::cin >> startDrawer;
        if (startDrawer == 'Y' or startDrawer == 'y')
        {
            std::cout << "\t\033[32mStarting...\033[0m" << std::endl;
            usleep(1000000);
        }
        else
        {
            return 0;
        }
    }

    std::cout << "\033[?25l" << std::endl;

    clearScreen();

    while (true)
    {
        std::vector<std::vector<std::string> > arr = readAndOutputFile("test.csv");
        int *windowSize = getWindowSize();
        std::string line = "\033[8;40m" + repeat("█", windowSize[0]) + "\n";
        std::string fullScreen = repeat(line, windowSize[1]);
        std::cout << fullScreen;
        moveCursorToColRow(std::stoi(arr[0][0]), std::stoi(arr[0][1]));
        std::cout << "\033[0;91;104m"
                  << lstrip(arr[0][2])
                  << "\033[0;91;40m";

        for (int i = 0; i < arr.size(); ++i)
        {
            moveCursorToColRow(std::stoi(arr[i][0]), std::stoi(arr[i][1]));
            std::cout << "\033[0;91;104m"
                      << lstrip(arr[i][2])
                      << "\033[0;91;40m";
        }

        std::string line2 = "\033[8m" + repeat("█", windowSize[0]);
        std::cout << line2 << std::endl;

        // in microseconds even tho param says seconds...
        usleep(2000000);
        clearScreen();
    }
    return 0;
}
