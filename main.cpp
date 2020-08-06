#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ParsedFlag {
    string flag, value;

    ParsedFlag init(string f, string v)
    {
        flag = f;
        value = v;

        return *this;
    }
};

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

int main(int argc, char** argv)
{
    vector<string> _;
    vector<ParsedFlag> flags;

    for (int i = 0; i < argc; i++)
    {
        string arg = argv[i];
        string ahead = argv[i + 1] ? argv[i + 1] : "";
        ParsedFlag flag;

        if (arg.find("--") <= arg.max_size()) {
            arg.erase(arg.find("-"), 2);

            if (arg.find('=') <= arg.max_size()) {
                vector<string> splitten = split(arg, "=", _);
                string f = splitten[0];
                string v = splitten[1];

                flag.init(f, v);
            }

            else if (ahead.length() > 0 && ahead.find('-') >= ahead.max_size())
                flag.init(arg, ahead);


            else if (ahead.length() > 0 && ahead.find('-') <= ahead.max_size())
                flag.init(arg, arg);

        }
        else if (arg.find('-') <= arg.max_size()) {
            arg.erase(arg.find('-'), 1);

            if (arg.find('=') <= arg.max_size()) {
                vector<string> splitten = split(arg, "=", _);
                string f = splitten[0];
                string v = splitten[1];

                flag.init(f, v);
            }

            else if (ahead.length() > 0 && ahead.find('-') >= ahead.max_size())
                flag.init(arg, ahead);


            else if (ahead.length() > 0 && ahead.find('-') <= ahead.max_size())
                flag.init(arg, arg);

        }
        if (flag.flag.length() > 0 && flag.value.length() > 0) flags.push_back(flag);
    }

    for (auto f : flags)
    {
        cout << "(" << f.flag << ", " << f.value << ")" << endl;
    }

    return 0;
}