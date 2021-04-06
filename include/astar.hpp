/* astar.hpp
    Defines the class which will implement the A* algorithm.
*/

#include "bfs.hpp"

#ifndef ASTAR_H
#define ASTAR_H

namespace Algorithms
{
    class AStarComparator
    {
        public:
            bool operator()(Algorithms::PQElement a, Algorithms::PQElement b);
    };

    class AStar : public Algorithms::BFS<AStarComparator>
    {
    };
} 

#endif