#ifndef FIND_H
#define FIND_H

#include <string>
#include <regex>
#include <vector>

using namespace std;

vector<string> find_all(string input, smatch match, regex pattern, vector<string> matches);

#endif