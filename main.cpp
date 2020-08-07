#include "split.h"
#include "parse.h"
#include "replace.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_equal(const ParsedFlag &a, const ParsedFlag &b)
{
    return a.flag == b.flag && a.flag == b.value;
}

int main()
{
    string input = "your mom --gay=yes --verbose=\"haha ok\" --desc \"yeah okay\" -a 2 -c -f -g=1 -abc=1 --reee";
    vector<ParsedFlag> args = get_flags(input);

    for (auto f : args)
    {
        cout << "(" << f.flag << ", " << f.value << ")" << endl;
    }

    return 0;
}