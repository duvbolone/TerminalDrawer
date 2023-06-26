#ifndef TERMINAL_H
#define TERMINAL_H

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "string.h"

#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <unistd.h>
#elif __APPLE__
#include <mach-o/dyld.h>
#endif

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

std::string getExecutablePath()
{
    char buffer[4096]; // Use a reasonable buffer size
#ifdef _WIN32
    GetModuleFileNameA(nullptr, buffer, sizeof(buffer));
#elif __linux__
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1)
    {
        buffer[len] = '\0';
    }
#elif __APPLE__
    uint32_t size = sizeof(buffer);
    if (_NSGetExecutablePath(buffer, &size) == 0)
    {
        return std::string(buffer);
    }
#endif
    return std::string(buffer);
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