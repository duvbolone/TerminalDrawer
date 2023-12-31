#ifndef CSV_H
#define CSV_H

#include "../include/terminal.h"
#include "../include/csvparser.h"

void csvDrawer(int argc, const char **argv)
{
    std::string file;
    std::cout << "\t What csv file would you like to use?\033[0m (*.csv)";
    std::cin >> file;

    std::cout << "\033[?25l" << std::endl;

    int cycle = 0;
    while (true)
    {
        clearScreen();
        std::vector<std::vector<std::string>> arr = readAndOutputFile(file);
        int *windowSize = getWindowSize();
        std::string line = "\033[8;40m" + repeat("█", windowSize[0]) + "\n";
        std::string fullScreen = repeat(line, windowSize[1]);
        std::cout << fullScreen;

        if (containsArg(argc, argv, "--status"))
        {
            moveCursorToColRow(0, 0);
            std::cout << "\033[0m"
                      << "\033[1mStatus\033[0m -  cycle: \033[1;92m" << cycle << "\033[0m"
                      << " - one cycle every \033[1;92m2 \033[0msecond"
                      << " - wsize: \033[1;92m" << windowSize[0] << "\033[0m x \033[1;92m" << windowSize[1]
                      << "\033[0;40m";
        }

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

        std::string line2 = "\033[8m" + repeat("█", windowSize[0]);
        std::cout << line2 << std::endl;

        // in microseconds even tho param says seconds...
        usleep(200000);
        cycle++;
    }
}
#endif