#include <vector>

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

    void aStar();
    void bfsGraph();
    void idfs();
    void idastar();
    void gbfs();
}

#endif