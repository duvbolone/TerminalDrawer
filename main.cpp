#include "include/tools.h"
#include "include/csvparser.h"

#include "modes/clock.h"
#include "modes/csv.h"

int main(int argc, const char **argv)
{
    bool paramMode = false;
    std::string mode;
    if (containsArg(argc, argv, "--no-start"))
    {
        paramMode = true;
        std::cout << "\t\033[32mStarting...\033[0m" << std::endl;
        usleep(1000000);
    }
    else
    {
        paramMode = false;
        std::string bars = repeat("=", (getWindowSize()[0] / 2) - 9);
        std::cout << "\033[36m\033[?25h" + bars + "||\033[31mTerminalDrawer\033[36m||" + bars + "\033[0m" << std::endl;
        std::cout << "\t Welcome to \033[1mTerminalDrawer\033[0m" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "\t Would you like to start the draw process? \033[93m(this will clear the terminal!)\033[0m (Y/N)";

        char startDrawer;
        std::cin >> startDrawer;
        if (startDrawer == 'Y' or startDrawer == 'y')
        {
            std::cout << "\t What mode would you like to start in?\033[0m (csv, clock)";
            std::cin >> mode;
            std::cout << "\t\033[32mStarting...\033[0m" << std::endl;
            usleep(1000000);
        }
        else
        {
            return 0;
        }
    }

    if (paramMode)
    {
        if (containsArg(argc, argv, "--csv"))
        {
            csvDrawer(argc, argv);
        }
        if (containsArg(argc, argv, "--clock"))
        {
            clockDrawer(argc, argv);
        }
    } else {
        if (mode == "csv")
        {
            csvDrawer(argc, argv);
        }
        if (mode == "clock")
        {
            clockDrawer(argc, argv);
        }
    }
}
