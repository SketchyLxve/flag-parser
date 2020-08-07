#ifndef REPLACE_H
#define REPLACE_H

#include <string>
#include <vector>


struct Spaced {
    std::string output;
    std::vector<std::size_t> positions;

    Spaced init(std::string o, std::vector<std::size_t> p)
    {
        output = o;
        positions = p;

        return *this;
    }

};

struct ReplacedValue {
    std::string output;
    std::vector<std::size_t> positions;

    ReplacedValue init(std::string o, std::vector<std::size_t> p)
    {
        output = o;
        positions = p;

        return *this;
    }
};

struct RemovedSpaces {
    std::string output;
    std::vector<ReplacedValue> values;

    RemovedSpaces init(std::string o, std::vector<ReplacedValue> v)
    {
        output = o;
        values = v;

        return *this;
    }
};

Spaced remove_space(std::string input, std::vector<size_t> positions);

RemovedSpaces replace_spaces_in_quotes(std::string input);

std::vector<std::string> extract_values(std::string input, std::vector<std::string> store);

#endif