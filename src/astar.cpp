#include "astar.hpp"

bool Algorithms::AStarComparator::operator()(PQElement a, PQElement b)
{
    int ha = a.first;
    int hb = b.first;
    int fa = a.second->path_cost + ha;
    int fb = b.second->path_cost + hb;

    if (fa == fb)
    {
        return ha >= hb;
    }
    else
    {
        return fa >= fb;
    }
}

Algorithms::Response Algorithms::AStar::algorithm(State* state)
{
    Algorithms::PriorityQueue open;
    std::unordered_set<Node, Node::Node_Hash> closed;
    
    open.put(this->initial, this->heuristic.run(*(this->initial->state)));

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
                open.put(nextNode, this->heuristic.run(*(nextNode->state)));
            }
        }
    }

    throw Algorithms::UnsolvableProblem();
}