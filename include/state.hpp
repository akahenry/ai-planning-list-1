#include <map>

#include "instance.hpp"
#include "actions.hpp"

#ifndef STATE_H
#define STATE_H

class State
{
    private:
        int id;
        static int hash(const Instance &instance);

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
        std::map<Actions, State> succ();
        State nextState(Actions action);
        bool isGoal();
        int getId();

        State& operator=(const State &state);
        bool operator==(const State &state) const;
        bool operator!=(const State &state);

        static State getState(Instance instance);
        static void insertState(State state);
        static void deleteState(State state);
};

#endif