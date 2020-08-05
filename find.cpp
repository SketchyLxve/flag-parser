#include "find.h"

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

vector<string> find_all(string input, smatch match, regex pattern, vector<string> matches)
{
    regex_search(input, match, pattern);

    if (match[0].matched) {
        matches.push_back(match[0].str());
        input = input.replace(input.find(match[0].str()), match[0].str().length(), "");
        return find_all(input, match, pattern, matches);
    }
    
    else return matches;
}