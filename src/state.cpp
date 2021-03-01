#include "state.hpp"

State::State(Instance instance)
{
    this->instance = instance;
}

State State::nextState(Actions action)
{
    return State(this->instance.nextInstance(action));
}

std::map<Actions, State> State::succ()
{
    std::map<Actions, State> map;

    for(Actions action = Actions::UP; action <= Actions::DOWN; action = Actions(int(action) + 1))
    {
        map.insert({action, this->nextState(action)});
    }

    return map;
}

