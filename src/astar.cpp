#include "astar.hpp"

bool Algorithms::AStarComparator::operator()(PQElement a, PQElement b)
{
    int ha = a.first.first;
    int hb = b.first.first;
    int fa = a.second->path_cost + ha;
    int fb = b.second->path_cost + hb;
    int ca = a.first.second;
    int cb = b.first.second;

    if (fa == fb)
    {
        if (ha == hb)
        {
            return ca <= cb;
        }
        else 
        {
            return ha >= hb;
        }
    }
    else
    {
        return fa >= fb;
    }
}

template struct Algorithms::BFS<Algorithms::AStarComparator>;