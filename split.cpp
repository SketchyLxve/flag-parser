#include "split.h"

#include <string>
#include <vector>

using namespace std;

vector<string> split(string input, string delim, vector<string> store)
{
    if (input.find(delim) >= input.max_size()) {
        store.push_back(input);
        return store;
    }

    string sub = input.substr(0, input.find(delim));
    store.push_back(sub);
    input.erase(input.find(sub), sub.length() + delim.length());

    return split(input, delim, store);
}