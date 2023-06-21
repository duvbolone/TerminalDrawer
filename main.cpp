#include "headers/tools.h"
#include "headers/csvparser.h"

#include "modes/clock.h"
#include "modes/csv.h"

int main(int argc, const char **argv)
{
    if (containsArg(argc, argv, "--no-start"))
    {
        std::cout << "\t\033[32mStarting...\033[0m" << std::endl;
        usleep(1000000);
    }
    else
    {
        std::string bars = repeat("=", (getWindowSize()[0] / 2) - 8);
        std::cout << "\033[36m\033[?25h" + bars + "||\033[31mScreenDrawer\033[36m||" + bars + "\033[0m" << std::endl;
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

    if (containsArg(argc, argv, "--csv"))
    {
        csvDrawer();
    }
    if (containsArg(argc, argv, "--clock"))
    {
        clockDrawer();
    }
}
