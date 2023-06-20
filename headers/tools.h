#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>

#ifndef TOOLS_H
#define TOOLS_H
void clearScreen()
{
    std::system("clear && printf '\033[3J'");
}

int *getWindowSize()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int *size = new int[2];
    size[0] = w.ws_col;
    size[1] = w.ws_row;

    return size;
}

void moveCursorToRowCol(int row = 0, int col = 0)
{
    std::cout << "\033[" << row << ";" << col << "H";
}

void clearCurrentLine()
{
    std::cout << "\033[2K";
}

std::string repeat(const std::string &str, int count)
{
    std::string result;

    for (int i = 0; i < count; ++i)
    {
        result += str;
    }

    return result;
}

#endif