#include <iostream>
#include <chrono>
#include <vector>
#include <deque>
#include <unordered_set>
#include <map>

#include "actions.hpp"
#include "closedlist.hpp"
#include "heuristic.hpp"
#include "openlist.hpp"
#include "node.hpp"
#include "state.hpp"

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

namespace Algorithms
{
    struct Response
    {
        std::vector<Actions> actionSequence;
        int expandedNodes;
        int optimalSolutionSize;
        float elapsedTime;
        float meanHeuristicFunction;
        int initialHeuristicFunction;
    };

    struct UnsolvableProblem : public std::exception
    {
        const char * what () const throw ()
        {
            return "Problem is unsolvable.";
        }
    };

    Response createResponse(Node initial, std::vector<Actions> actions, std::chrono::_V2::system_clock::time_point startPoint, int expandedNodes, Heuristic heuristic);

    Response bfsGraph(State* instance);
    void aStar();
    void idfs();
    void idaStar();
    void gbfs();
}

#endif