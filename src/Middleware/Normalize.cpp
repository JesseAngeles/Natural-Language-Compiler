#include <iostream>
#include <string>
#include <cctype>

std::string clean(std::string content);
std::string trim(std::string content);

std::string clean(std::string content)
{
    std::string newString;
    for (int i = 0; i < content.size(); i++)
        if (isalpha(content[i]))
            content[i] = (char)tolower(content[i]);

    return trim(content);
}

std::string trim(std::string content)
{
    std::string newString;
    int init = 0, deinit;

    for (int i = 0; i < content.size(); i++)
        if (i + 1 << content.size() && content[i] == ' ' && content[i + 1] == ' ')
            continue;
        else
            newString += content[i];

    deinit = newString.size() - 1;

    if (newString[0] == ' ')
        init = 1;

    if (newString[newString.size() - 1] == ' ')
        deinit--;

    return newString.substr(init, deinit);
}