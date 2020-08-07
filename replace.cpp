#include "replace.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Spaced remove_space(string input, vector<size_t> positions)
{
    if (input.find(' ') >= input.max_size()) {
        Spaced val;
        val.init(input, positions);
        return val;
    }

    string copy = input;
    ReplacedValue temp;
    size_t space = input.find(' ');
    positions.push_back(space);
    input.erase(space, 1);

    temp.init(input, positions);

    return remove_space(input, positions);
}

RemovedSpaces replace_spaces_in_quotes(string input)
{
    vector<size_t> __;
    vector<string> _;
    vector<string> values = extract_values(input, _);
    vector<ReplacedValue> replaced;
    RemovedSpaces result;

    for (string v : values)
    {
        Spaced spaceless = remove_space(v, __);
        ReplacedValue temp;
        temp.output = spaceless.output;
        temp.positions = spaceless.positions;
        replaced.push_back(temp);
        if (input.find(v) <= input.max_size())
            input = input.replace(input.find(v), v.length(), spaceless.output);
    }

    result.init(input, replaced);

    return result;
}

vector<string> extract_values(string input, vector<string> store)
{
    string copy = input;
    if (input.find('"') >= input.max_size() || copy.replace(copy.find('"'), 1, "").find('"') >= copy.max_size()) return store;

    size_t first = input.find('"');
    size_t second = input.erase(first, 1).find('"');
    string sub = input.substr(first, second - first);

    store.push_back(sub);
    input.erase(second, 1);
    input = input.replace(input.find(sub), sub.length(), "");

    return extract_values(input, store);
}