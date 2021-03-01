#include <string.h>
#include <vector>
#include <iostream>
#include "algorithms.hpp"
#include "state.hpp"

#ifndef PARSER_H
#define PARSER_H

struct Program
{
    Algorithms::Types algorithm;
    std::vector<State> states;
};

namespace Parser
{
    Algorithms::Types hashit(char* str);
    Program* parse(int argc, char** argv);
}

#endif