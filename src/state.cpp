#include "state.hpp"

std::size_t State::hash(const Instance &instance)
{
    return Instance::Instance_Hash()(instance);
}

State* State::getState(Instance instance)
{
    int hashResult = hash(instance);
    if(!states.count(hashResult))
    {
        State* state = new State(instance);
        State::insertState(state);
        return state;
    }
    else
    {
        return states.at(hashResult);
    }
}

void State::insertState(State* state)
{
    states.insert({state->id, state});
}

void State::deleteState(State* state)
{
    states.erase(state->id);
    delete state;
}

State::State()
{
    this->id = -1;
}

State::State(Instance instance)
{
    this->id = hash(instance);
    this->instance = instance;
}

State* State::nextState(Actions action)
{
    Instance nextInstance = this->instance.nextInstance(action);
    State* got = State::getState(nextInstance);

    return got;
}

bool State::isGoal()
{
    return Instance::isGoal(this->instance);
}

std::size_t State::getId()
{
    return this->id;
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
