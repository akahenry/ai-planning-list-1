#include <vector>
#include "graph.hpp"

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

namespace Algorithms
{
    enum Types
    {
        BFS,
        IDFS,
        ASTAR,
        IDASTAR,
        GBFS,
        NONE
    };

    template <typename Action_Type, typename State_Type> struct ActionState
    {
        Action_Type action;
        State_Type state;
    };

    struct UnsolvableProblem : public std::exception
    {
        const char * what () const throw ()
        {
            return "Problem is unsolvable.";
        }
    };

    template <typename State_Type> bool isGoal(State_Type state);
    template <typename Action_Type, typename State_Type> std::vector<ActionState<Action_Type, State_Type>> succ(State_Type state);

    template <class State_Type, class Action_Type, typename T> void bfsGraph(State_Type instance);
    void aStar();
    void idfs();
    void idaStar();
    void gbfs();
}

#endif