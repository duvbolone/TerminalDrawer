#ifndef TERMINAL_H
#define TERMINAL_H

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "string.h"

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

void moveCursorToColRow(int col = 0, int row = 0)
{
    std::cout << "\033[" << row << ";" << col << "H ";
    std::cout.flush();
}


void clearCurrentLine()
{
    std::cout << "\033[2K";
}

std::string getCurrentDirectory()
{
    char cwd[4096];
    if (getcwd(cwd, sizeof(cwd)) != nullptr)
    {
        return std::string(cwd);
    }
    return "";
}

bool containsArg(int arg_count, const char *args[], const char sub_string[])
{
    for (int i = 0; i < arg_count; i++)
    {
        if (containsString(args[i], sub_string))
        {
            return true;
        }
    }
    return false;
}

#endif