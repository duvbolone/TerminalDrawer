#ifndef CSV_H
#define CSV_H

#include "../headers/tools.h"
#include "../headers/csvparser.h"

void csvDrawer() {
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
            if (arr[i].size() < 3)
            {
                continue;
            } 
            else
            {
                moveCursorToColRow(std::stoi(arr[i][0]), std::stoi(arr[i][1]));
                std::cout << "\033[0;91m"
                        << lstrip(arr[i][2])
                        << "\033[0;91;40m";
            }
        }

        // std::string line2 = "\033[8m" + repeat("█", windowSize[0]);
        // std::cout << line2 << std::endl;

        // in microseconds even tho param says seconds...
        usleep(2000000);
        clearScreen();
    }
}
#endif