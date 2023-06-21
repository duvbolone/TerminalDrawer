#ifndef TOOLS_H
#define TOOLS_H

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>


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

std::string lstrip(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start != std::string::npos)
    {
        return str.substr(start);
    }
    return str;
}

bool containsString(const char *mainStr, const char *subString)
{
    std::string strObj(mainStr);
    std::string::size_type pos = strObj.find(subString);
    return pos != std::string::npos;
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