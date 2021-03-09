#include "state.hpp"

State::State()
{
    this->instance = new Instance;
}

State::State(Instance* instance)
{
    this->instance = instance;
}

State* State::nextState(Actions action)
{
    Instance* nextInstance = this->instance->nextInstance(action);
    if(this->instance == nextInstance)
    {
        return this;
    }
    else
    {
        return new State(nextInstance);
    }
}

bool State::isGoal()
{
    return Instance::isGoal(*(this->instance));
}

std::map<Actions, State*> State::succ()
{
    std::map<Actions, State*> map;

    for(Actions action = Actions::UP; action <= Actions::DOWN; action = Actions(int(action) + 1))
    {
        map.insert({action, this->nextState(action)});
    }

    return map;
}

bool State::operator==(const State &state)
{
    return this->instance == state.instance;
}

