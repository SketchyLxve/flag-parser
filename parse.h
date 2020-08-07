#ifndef PARSE_H
#define PARSE_H

#include "replace.h"
#include <string>
#include <vector>

struct ParsedFlag {
    std::string flag, value;

    ParsedFlag init(std::string f, std::string v)
    {
        flag = f;
        value = v;

        return *this;
    }

    bool operator==(const ParsedFlag& f) const
    {
        return f.flag == flag && f.value == value;
    }
};

std::vector<ParsedFlag> get_flags(std::string input);

#endif