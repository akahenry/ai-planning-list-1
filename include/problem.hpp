#include "actions.hpp"
#include "state.hpp"

#ifndef PROBLEM_H
#define PROBLEM_H

class Problem
{
    public:
        Actions actions;
        State initialState;
        State finalState; 

        static double cost(State state, Actions action);
        static State transition(State state, Actions action);
};

#endif