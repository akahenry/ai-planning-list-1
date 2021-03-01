#include <vector>
#include "graph.hpp"
#include "state.hpp"
#include "actions.hpp"

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

    struct ActionState
    {
        Actions action;
        State state;
    };

    struct UnsolvableProblem : public std::exception
    {
        const char * what () const throw ()
        {
            return "Problem is unsolvable.";
        }
    };

    bool isGoal(State state);
    std::vector<ActionState> succ(State state);

    std::vector<Actions> bfsGraph(State instance);
    void aStar();
    void idfs();
    void idaStar();
    void gbfs();
}

#endif