#include "gbfs.hpp"

bool Algorithms::GBFSComparator::operator()(PQElement a, PQElement b)
{
    int ha = a.first.first;
    int hb = b.first.first;
    int ga = a.second->path_cost;
    int gb = b.second->path_cost;
    int ca = a.first.second;
    int cb = b.first.second;

    if (ha == hb)
    {
        if (ga == gb)
        {
            return ca <= cb;
        }
        else 
        {
            return ga <= gb;
        }
    }
    else
    {
        return ha >= hb;
    }
}

template struct Algorithms::BFS<Algorithms::GBFSComparator>;