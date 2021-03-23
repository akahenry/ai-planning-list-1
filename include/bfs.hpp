#include <queue>
#include <unordered_set>

#include "basealgorithm.hpp"

#ifndef BFS_H
#define BFS_H

namespace Algorithms 
{
    typedef std::pair<int, Node> PQElement;

    template <class comparator>
    struct PriorityQueue {
        std::priority_queue<PQElement, std::vector<PQElement>,
                        comparator> elements;

        inline bool empty() const {
            return elements.empty();
        }

        inline void put(Node item, int priority) {
            elements.emplace(priority, item);
        }

        Node get() {
            Node best_item = elements.top().second;
            elements.pop();
            return best_item;
        }
    };

    template <class comparator> 
    class BFS : public BaseAlgorithm
    {
        protected:
            Response algorithm(State state)
            {
                Algorithms::PriorityQueue<comparator> open;
                std::unordered_set<Node, Node::Node_Hash> closed;
                
                open.put(this->initial, this->heuristic.run(this->initial.state));

                while(!open.empty())
                {
                    Node node = open.get();
                    this->expandedCount++;

                    if(!closed.count(node))
                    {
                        closed.insert(node);
                        
                        if(node.state.isGoal())
                        {
                            return this->createResponse(Node::extract_path(node, this->initial.state));
                        }

                        for(Node nextNode : BaseAlgorithm::adjacents(&node))
                        {
                            open.put(nextNode, this->heuristic.run(nextNode.state));
                        }
                    }
                }

                throw Algorithms::UnsolvableProblem();
            };
    };
}

#endif