#include <limits>

#include "basealgorithm.hpp"

#ifndef IDASTAR_H
#define IDASTAR_H

namespace Algorithms 
{
    struct IntOrNone
    {
        int value;
        bool isNone;
    };

    struct ActionsOrNone
    {
        std::vector<Actions> actions;
        bool isNone;
    };

    class IDAStar : public BaseAlgorithm
    {
        private:
            std::pair<IntOrNone, ActionsOrNone> recursiveSearch(Node* node, int limit);

        protected:
            Response algorithm(State* state);
    };
}

#endif