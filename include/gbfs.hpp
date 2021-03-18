#include "bfs.hpp"

#ifndef GBFS_H
#define GBFS_H

namespace Algorithms 
{
    class GBFSComparator
    {
        public:
            bool operator()(Algorithms::PQElement a, Algorithms::PQElement b);
    };

    class GBFS : public Algorithms::BFS<GBFSComparator>
    {
    };
}

#endif