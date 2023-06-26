#ifndef STRING_H
#define STRING_H

#include <string>

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

std::vector<std::string> split(std::string string, const std::string delim) {
    std::vector<std::string> splitted;

    std::string buffer;

    if (string[string.length() - 1] != '/') {
        string += "/";
    }

    for (int i = 0; i < string.length(); i++) {
        if (string[i] == '/') {
            splitted.push_back(buffer);
            buffer = "";
        } else {
            buffer += string[i];
        }
    }

    return splitted;
}

bool containsString(const char *mainStr, const char *subString)
{
    std::string strObj(mainStr);
    std::string::size_type pos = strObj.find(subString);
    return pos != std::string::npos;
}

#endif