#include "parse.h"
#include "find.h"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
  string input = "your mom --gay=true --additional=\"very fucking dumb\"";
  vector<ParsedFlag> flags = parse_flags(input);

  for (int i = 0; i < flags.size(); i++)
    cout << "Initial: "  << flags[i].initial << "\nFlag: " << flags[i].flag << "\nValue: " << flags[i].value << endl;
  return 0;
}