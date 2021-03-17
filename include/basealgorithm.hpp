#include <iostream>
#include <chrono>
#include <vector>

#include "actions.hpp"
#include "heuristic.hpp"
#include "node.hpp"
#include "state.hpp"

#ifndef BASEALGORITHM_H
#define BASEALGORITHM_H

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

    class BaseAlgorithm
    {
        protected:
            // Statistics
            std::chrono::_V2::system_clock::time_point startTime;
            std::chrono::_V2::system_clock::time_point endTime;
            float duration = 0;
            int expandedCount = 0;

            // Functionalities
            Heuristic heuristic;
            Node* initial;

            // Methods
            Response createResponse(std::vector<Actions> actions);
            std::vector<Node*> adjacents(Node* node);

            // Abstract
            virtual Response algorithm(State* state) = 0;

        public:
            Response run(State* state);
    };

    void idfs();
    void idaStar();
    void gbfs();
}

#endif