#ifndef CLOCK_H
#define CLOCK_H

#include "../include/terminal.h"
#include <string>

void clockDrawer(int argc, const char **argv)
{
    bool directionIsUp = false;
    bool directionIsLeft = false;
    int col = 1;
    int row = 1;
    int time[] = {0, 0}; // minutes, seconds
    std::string betweenMandS;

    std::cout << "\033[?25l" << std::endl;

    clearScreen();

    int cycle = 0;
    while (true)
    // for (int i = 0; i < 5; i++)
    {
        int *windowSize = getWindowSize();
        std::string line = "\033[8;40m" + repeat("█", windowSize[0]) + "\n";
        std::string fullScreen = repeat(line, windowSize[1]);
        std::cout << fullScreen;

        if (row >= windowSize[1] - 2)
        {
            directionIsUp = true;
        }
        if (row <= 2)
        {
            directionIsUp = false;
        }
        if (col >= windowSize[0] - 2)
        {
            directionIsLeft = true;
        }
        if (col <= 2)
        {
            directionIsLeft = false;
        }

        if (time[1] < 10)
        {
            betweenMandS = ":0";
        }
        else
        {
            betweenMandS = ":";
        }

        if (containsArg(argc, argv, "-s"))
        {
            moveCursorToColRow(0, 0);
            std::cout << "\033[0m"
                      << "\033[1mStatus\033[0m -  cycle: \033[1;92m" << cycle << "\033[0m - u: \033[1;92m" << directionIsUp << "\033[0m l: \033[1;92m" << directionIsLeft
                      << "\033[0m - row: \033[1;92m" << row << "\033[0m - col: \033[1;92m" << col
                      << "\033[0m - wsize: \033[1;92m" << windowSize[0] << "\033[0m x \033[1;92m" << windowSize[1]
                      << "\033[0;40m";
        }

        moveCursorToColRow(col, row);
        std::cout << "\033[0;91;104m" + std::to_string(time[0]) + betweenMandS + std::to_string(time[1]) + "\033[0;91;40m";
        // std::cout << "\033[0;91;104m"
        //           << "x: " << directionIsLeft << " y: " << directionIsUp << "\033[0;91;40m";

        std::string line2 = "\033[8m" + repeat("█", windowSize[0]);
        std::cout << line2 << std::endl;
        time[1]++;
        if (time[1] >= 60)
        {
            time[1] = 0;
            time[0]++;
        }
        if (directionIsUp)
        {
            row--;
        }
        else
        {
            row++;
        }
        if (directionIsLeft)
        {
            col--;
        }
        else
        {
            col++;
        }

        // in microseconds even tho param says seconds...
        usleep(1000000);
        cycle++;
        clearScreen();
    }
}
#endif