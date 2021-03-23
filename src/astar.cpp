#include "astar.hpp"

bool Algorithms::AStarComparator::operator()(PQElement a, PQElement b)
{
    int ha = a.first;
    int hb = b.first;
    int fa = a.second.path_cost + ha;
    int fb = b.second.path_cost + hb;

    if (fa == fb)
    {
        return ha >= hb;
    }
    else
    {
        return fa >= fb;
    }
}