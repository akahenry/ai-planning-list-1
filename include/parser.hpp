#include <string.h>
#include <vector>
#include <iostream>

#include "state.hpp"

#ifndef PARSER_H
#define PARSER_H

enum Types
{
    BFS,
    IDFS,
    ASTAR,
    IDASTAR,
    GBFS,
    NONE
};

struct Program
{
    Types algorithm;
    std::vector<State> states;
};

namespace Parser
{
    Types hashit(char* str);
    Program* parse(int argc, char** argv);
}

#endif