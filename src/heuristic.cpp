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

    this->counter++;
    this->acc += result;

    return result;
}