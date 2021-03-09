#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <map>

#include "actions.hpp"
#include "closedlist.hpp"
#include "openlist.hpp"
#include "node.hpp"
#include "state.hpp"

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

namespace Algorithms
{
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

    std::vector<Actions> bfsGraph(State* instance);
    void aStar();
    void idfs();
    void idaStar();
    void gbfs();
}

#endif