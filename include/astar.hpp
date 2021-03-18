#include <queue>
#include <unordered_set>

#include "basealgorithm.hpp"

#ifndef ASTAR_H
#define ASTAR_H

namespace Algorithms
{
    typedef std::pair<int, Node*> PQElement;

    class AStarComparator
    {
        public:
            bool operator()(PQElement a, PQElement b);
    };

    class AStar : public BaseAlgorithm
    {
        protected:
            Response algorithm(State* state);
    };

    struct PriorityQueue {
        std::priority_queue<PQElement, std::vector<PQElement>,
                        AStarComparator> elements;

        inline bool empty() const {
            return elements.empty();
        }

        inline void put(Node* item, int priority) {
            elements.emplace(priority, item);
        }

        Node* get() {
            Node* best_item = elements.top().second;
            elements.pop();
            return best_item;
        }
    };
} 

#endif