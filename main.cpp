#include "main.h"
#include "headers/tools.h"

int main(int argc, char **argv)
{
    // std::string bars = repeat("=", (getWindowSize()[0]/2) - 8);
    // std::cout << "\033[36m" + bars + "||\033[31mScreenDrawer\033[36m||" + bars + "\033[0m" << std::endl;
    // std::cout << "\t Welcome to \033[1mScreenDrawer\033[0m" << std::endl;
    // std::cout << "" << std::endl;
    // std::cout << "\t Would you like to start the draw process? \033[93m(this will clear the terminal!)\033[0m (Y/N)";

    // char startDrawer;
    // std::cin >> startDrawer;
    // if (startDrawer == 'Y' or startDrawer == 'y')
    // {
    //     std::cout << "\t\033[32mStarting...\033[0m" << std::endl;
    //     usleep(1000000);
    // }
    // else
    // {
    //     return 0;
    // }

    // std::cout << "X,Y of point: ";
    // char rowAndColInput[32];
    // std::cin >> rowAndColInput;
    // int row = strtok(rowAndColInput, ",")[0];
    // int col = strtok(rowAndColInput, ",")[1];
    bool directionIsUp = false;
    bool directionIsLeft = false;
    int row = 1;
    int col = 1;
    int time[] = {0, 0}; // minutes, seconds
    std::string betweenMandS;

    std::cout << "\033[?25l" << std::endl;

    clearScreen();

    while (true)
    // for (int i = 0; i < 5; i++)
    {
        moveCursorToRowCol();
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
        moveCursorToRowCol(row, col);
        // std::cout << "\033[0;91;104m" + std::to_string(time[0]) + betweenMandS + std::to_string(time[1]) + "\033[0;91;40m";
        std::cout << "\033[0;91;104m"
                  << "x: " << directionIsLeft << " y: " << directionIsUp << "\033[0;91;40m";

        std::string line2 = "\033[8m" + repeat("█", windowSize[0]);
        std::cout << line2 << std::endl;
        time[1]++;
        if (time[1] >= 60)
        {
            time[1] = 0;
            time[0]++;
        }
        col++;
        col++;
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
        // usleep(1000000);
        usleep(500000);
        clearScreen();
    }
    return 0;
}
