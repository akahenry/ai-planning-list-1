#include "bfsgraph.hpp"

Algorithms::Response Algorithms::BFSGraph::algorithm(State state)
{
    std::deque<Node> open;
    std::unordered_set<Node, Node::Node_Hash> closed;

    if(this->initial.state.isGoal())
    {
        return Algorithms::BaseAlgorithm::createResponse(std::vector<Actions>());
    }

    open.push_back(this->initial);
    closed.insert(this->initial);
    while(!open.empty())
    {
        Node node = open[0];
        this->expandedCount++;

        for(Node nextNode : BaseAlgorithm::adjacents(node))
        {
            if(nextNode.state.isGoal())
            {
                return Algorithms::BaseAlgorithm::createResponse(Node::extract_path(nextNode, this->initial.state));
            }
            else if (!closed.count(nextNode))
            {
                closed.insert(nextNode);
                open.push_back(nextNode);
            }
        }
        open.pop_front();
    }

    throw Algorithms::UnsolvableProblem();
}