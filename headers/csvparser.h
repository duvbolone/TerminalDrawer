#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<std::string> > readAndOutputFile(const std::string &filename)
{
    std::vector<std::vector<std::string> > outputArray;
    std::ifstream MyReadFile(filename);

    if (MyReadFile.is_open())
    {
        std::string line;
        while (getline(MyReadFile, line))
        {
            std::vector<std::string> tokens;
            std::stringstream ss(line);
            std::string token;

            while (getline(ss, token, ','))
            {
                tokens.push_back(token);
            }

            outputArray.push_back(tokens);
        }

        MyReadFile.close();
    }
    else
    {
        std::cerr << "Failed to open file: " << filename << '\n';
    }

    return outputArray;
}

#endif
