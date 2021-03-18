#include "gbfs.hpp"

bool Algorithms::GBFSComparator::operator()(PQElement a, PQElement b)
{
    int ha = a.first;
    int hb = b.first;
    int ga = a.second->path_cost;
    int gb = b.second->path_cost;

    if (ha == hb)
    {
        return ga >= gb;
    }
    else
    {
        return ha >= hb;
    }
}

template struct Algorithms::BFS<Algorithms::GBFSComparator>;