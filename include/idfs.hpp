#include "basealgorithm.hpp"

#ifndef IDFS_H
#define IDFS_H

namespace Algorithms 
{
    class IDFS : public BaseAlgorithm
    {
        protected:
            Response algorithm(State* state);

        private:
            std::pair<std::vector<Actions>, bool> dls(Node* node, int depth);
    };
}

#endif