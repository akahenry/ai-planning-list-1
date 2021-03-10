#include "state.hpp"

int State::hash(const Instance &instance)
{
    return Instance::Instance_Hash()(instance);
}

State* State::getState(Instance* instance)
{
    try
    {
        int hashResult = hash(*instance);
        if(states.find(hashResult) != states.end())
            return nullptr;
        else
        {
            return states.at(hashResult);
        }
    } 
    catch(std::out_of_range& e) 
    {
        return nullptr;
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
    this->instance = new Instance;

    State::insertState(this);
}

State::State(Instance* instance)
{
    State* got = State::getState(instance);
    
    if(got != nullptr)
    {
        this->id = got->id;
        this->instance = got->instance;
    }
    else
    {
        this->id = hash(*instance);
        this->instance = instance;
        State::insertState(this);
    }    
}

State* State::nextState(Actions action)
{
    Instance* nextInstance = this->instance->nextInstance(action);
    State* got = State::getState(nextInstance);

    if(got != nullptr)
    {
        return got;
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

int State::getId()
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
    *(this->instance) = *(state.instance);

    return *this;
}

bool State::operator==(const State &state)
{
    if (this->instance == nullptr)
    {
        return state.instance == nullptr;
    }
    else
    {
        return this->instance == state.instance;
    }
}

bool State::operator!=(const State &state)
{
    return !(*this == state);
}
