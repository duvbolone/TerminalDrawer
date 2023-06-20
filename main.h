#include <iostream>
#include <string>

#ifndef MAIN_H
#define MAIN_H
bool containsString(const char *mainStr, const char *subString)
{
    std::string strObj(mainStr);
    auto pos = strObj.find(subString);
    return pos != std::string::npos;
}

bool containsArg(int arg_count, const char *args[], char sub_string[])
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