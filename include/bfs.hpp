/* bfs.hpp
    Defines the template class which will implement the BFS algorithm for any comparator.
*/

#include <queue>
#include <unordered_set>

#include "basealgorithm.hpp"

#ifndef BFS_H
#define BFS_H

namespace Algorithms 
{
    typedef std::pair<std::pair<int, int>, Node*> PQElement;

    template <class comparator>
    struct PriorityQueue {
        std::priority_queue<PQElement, std::vector<PQElement>,
                        comparator> elements;

        inline bool empty() const {
            return elements.empty();
        }

        inline void put(Node* item, int priority, int count) {
            elements.emplace(std::pair<int, int>{priority, count}, item);
        }

        Node* get() {
            Node* best_item = elements.top().second;
            elements.pop();
            return best_item;
        }
    };

    template <class comparator> 
    class BFS : public BaseAlgorithm
    {
        protected:
            Response algorithm(State* state)
            {
                Algorithms::PriorityQueue<comparator> open;
                std::unordered_set<Node, Node::Node_Hash> closed;
                int count = 0;
                
                open.put(this->initial, this->heuristic.run(*(this->initial->state)), count++);

                while(!open.empty())
                {
                    Node* node = open.get();

                    if(!closed.count(*node))
                    {
                        closed.insert(*node);
                        
                        if(node->state->isGoal())
                        {
                            return this->createResponse(Node::extract_path(*node, this->initial->state));
                        }

                        for(Node* nextNode : BaseAlgorithm::adjacents(node))
                        {
                            open.put(nextNode, this->heuristic.run(*(nextNode->state)), count++);
                        }
                    }
                }

                throw Algorithms::UnsolvableProblem();
            };
    };
}

#endif