#include "heuristic.hpp"

Heuristic::Heuristic()
{
    this->reset();
}

int Heuristic::count()
{
    return this->counter;
}

float Heuristic::mean()
{
    return float(this->acc)/this->counter;
}

void Heuristic::reset()
{
    this->counter = 0;
    this->acc = 0;
} 

int Heuristic::run(State state)
{
    int result = 0;
    std::vector<int> tiles = state.instance.getTiles();
    int size = tiles.size();
    int rootSize = std::sqrt(size);
    int x, y; // Optimal position
    int a, b; // Current position

    for(int i = 0; i < size; i++)
    {
        if(tiles[i] == 0)
        {
            continue;
        }
        x = tiles[i]/rootSize;
        y = tiles[i]%rootSize;

        a = i/rootSize;
        b = i%rootSize;

        result += std::abs(x - a) + std::abs(y - b);
    }

    this->counter++;
    this->acc += result;    

    return result;
}