#include "parse.h"
#include "split.h"
#include "replace.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<ParsedFlag> get_flags(string input)
{
    vector<string> _;
    RemovedSpaces res = replace_spaces_in_quotes(input);
    vector<string> values = split(res.output, " ", _);
    vector<ParsedFlag> flags;

    auto it = values.begin();

    ParsedFlag flag;

    while (it != values.end())
    {
        vector<string> _;
        string copy = it->substr(0, it->length());

        if (it == values.begin() && it->find('-') >= it->max_size()) {
            it = values.erase(it);
            continue;
        }

        if (it->find('-') <= it->max_size()) {

            if (
                copy.find('-') <= it->max_size() && copy.find('=') <= it->max_size() &&
                copy.substr(1, copy.find('=') - 1).length() == 3
                ) {
                copy.erase(copy.find('-'), 1);
                vector<string> s = split(copy, "=", _);
                vector<ParsedFlag> _flags;
                ParsedFlag _flag;

                for (int i = 0; i < 3; i++)
                {
                    string d = string(1, s[0][i]);
                    _flag.init(d, i < 2 ? d : s[1]);

                    flags.push_back(_flag);
                }

                ++it;
                continue;
            }

            string f = it->find("--") <= it->max_size()
                ? copy.erase(it->find("--"), 2)
                : copy.erase(it->find("-"), 1);

            flag.init(f, f);

            if (copy.find('=') <= it->max_size()) {
                vector<string> s = split(copy, "=", _);
                flag.init(s[0], s[1]);
            }

            else if (it != values.end() && (it + 1)->find('-') >= (it + 1)->max_size()) {
                string sub = it->substr(0, it->length());
                flag.init(
                    sub.find("--") <= sub.max_size() ? sub.erase(sub.find("--"), 2) : sub.erase(sub.find('-'), 1),
                    (it + 1)->substr(0, (it + 1)->length())
                );
            }

            if (flag.value.length() <= 0)
                flag.value = flag.flag;
        }

        ++it;
        auto iter = find_if(flags.begin(), flags.end(), [&](const ParsedFlag& t) { return flag.flag == t.flag && flag.value == t.value; });
        if (iter == flags.end())
            flags.push_back(flag);
    }

    int i = 0;
    for (auto f : flags)
    {
        string t;
        vector<size_t> _;
        Spaced spaceless = remove_space(f.value, _);
        string no_quotes = spaceless.output.find('"') <= spaceless.output.max_size()
            ? spaceless.output.erase(spaceless.output.find('"'), 1).erase(spaceless.output.find('"'), 1)
            : "";

        if (res.output.find(no_quotes) <= res.output.max_size()) {
            for (auto x : res.values)
            {
                if (x.output == no_quotes) {
                    for (auto p : x.positions)
                    {
                        t = x.output.insert(p, 1, ' ');
                    }

                    flags[i] = flag.init(f.flag, t);
                }
            }
        }

        i++;
    }

    return flags;
}