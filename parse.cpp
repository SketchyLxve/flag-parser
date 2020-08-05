#include "parse.h"
#include "find.h"

#include <iostream>
#include <stdio.h>
#include <regex>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

vector<ParsedFlag> parse_flags(string input)
{
    regex regexp(" ?-{1,2}\\w+=\"?(\\w+ ?\\w+?)+\"?");

    smatch match;

    vector<string> matches;
    vector<string> result = find_all(input, match, regexp, matches);

    vector<ParsedFlag> flags;

    for (string flag : result)
    {
        vector<string> res;

        boost::split(res, flag, boost::is_any_of("="));

        ParsedFlag temporary;
        temporary.init(flag, res[0], regex_replace(regex_replace(flag, regex(res[0] + "="), ""), regex("\""), ""));

        flags.push_back(temporary);
        input = regex_replace(input, regex(flag), "");
    }


    return flags;
}