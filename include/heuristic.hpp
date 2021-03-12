#include "state.hpp"

#ifndef HEURISTIC_H
#define HEURISTIC_H

class Heuristic
{
    private:
        int counter = 0;
        int acc = 0;

    public: 
        Heuristic();
        int count();
        float mean();
        void reset();
        int run(State state);
};

#endif