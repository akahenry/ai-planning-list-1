#include "state.hpp"

int State::hash(const Instance &instance)
{
    return Instance::Instance_Hash()(instance);
}

State::State()
{
    this->id = -1;
    this->instance = Instance();
}

State::State(Instance instance)
{
    this->id = hash(instance);
    this->instance = instance;
}

State State::nextState(Actions action)
{
    Instance nextInstance = this->instance.nextInstance(action);
    
    return State(nextInstance);
}

bool State::isGoal()
{
    return Instance::isGoal(this->instance);
}

int State::getId()
{
    return this->id;
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

State& State::operator=(const State &state)
{
    this->instance = state.instance;

    return *this;
}

bool State::operator==(const State &state) const
{
    return this->id == state.id;
}

bool State::operator!=(const State &state)
{
    return !(*this == state);
}
