#include "parse.h"
#include "find.h"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <array>

using namespace std;

int main()
{
    string input = "your mom --gay=true --additional=\"very fucking dumb\"";
    vector<ParsedFlag> flags = parse_flags(input);

    cout << "Input: " << input << "\n";

    for (int i = 0; i < flags.size(); i++)
        cout << "\n  Iteration " << i + 1 << "  |"
        << "\n================\n"
        << "Initial: "  << flags[i].initial
        << "\nFlag: " << flags[i].flag
        << "\nValue: " << flags[i].value << endl;
    return 0;
}