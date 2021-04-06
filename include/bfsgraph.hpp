/* bfsgraph.hpp
    Defines the class which will implement the BFS-Graph algorithm.
*/

#include <deque>
#include <unordered_set>

#include "basealgorithm.hpp"

#ifndef BFSGRAPH_H
#define BFSGRAPH_H

namespace Algorithms
{
    class BFSGraph : public Algorithms::BaseAlgorithm
    {
        protected:
            Algorithms::Response algorithm(State* state);
    };
}

#endif