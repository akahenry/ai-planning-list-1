/* state.hpp
    Defines the class which will implement the controller for all the states in the application.
    This class knows generates the sucessors of a state, knows which states is allocated, if the state
    is goal and more.
    Basically, it is the controller of the states.
*/

#include <map>

#include "instance.hpp"
#include "actions.hpp"

#ifndef STATE_H
#define STATE_H

class State
{
    private:
        std::size_t id;
        static std::size_t hash(const Instance &instance);

    public:
        Instance instance;

        struct State_Hash
        {
            size_t
            operator()(const State &obj) const
            {
                return State::hash(obj.instance);
            }
        };

        State();
        State(Instance instance);
        std::map<Actions, State*> succ();
        State* nextState(Actions action);
        bool isGoal();
        std::size_t getId();

        State& operator=(const State &state);
        bool operator==(const State &state) const;
        bool operator!=(const State &state);

        static State* getState(Instance instance);
        static void insertState(State* state);
        static void deleteState(State* state);
};

static std::map<std::size_t, State*> states;

#endif