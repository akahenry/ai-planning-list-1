#include <map>

#include "instance.hpp"
#include "actions.hpp"

#ifndef STATE_H
#define STATE_H

class State
{
    public:
        Instance instance;

        State(Instance instance);
        std::map<Actions, State> succ();
        State nextState(Actions action);
        bool isGoal();
};

#endif