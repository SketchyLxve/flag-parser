#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <vector>

struct ParsedFlag
{
    std::string initial, flag, value;

    ParsedFlag init(std::string i, std::string f, std::string v) {
        initial = i;
        flag = f;
        value = v;

        return *this;
    }
};

std::vector<ParsedFlag> parse_flags(std::string input);

#endif