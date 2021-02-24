#include <string.h>
#include <vector>
#include <iostream>
#include "algorithms.hpp"

#ifndef PARSER_H
#define PARSER_H

struct Program
{
    Algorithms::Types algorithm;
    std::vector<std::vector<int>> instances;
};

namespace Parser
{
    Algorithms::Types hashit(char* str);

    Program* parse(int argc, char** argv);
}

#endif