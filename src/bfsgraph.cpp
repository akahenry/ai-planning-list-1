#include "bfsgraph.hpp"

Algorithms::Response Algorithms::BFSGraph::algorithm(State* state)
{
    Algorithms::Response response;
    std::deque<Node*> open;
    std::unordered_set<Node, Node::Node_Hash> closed;

    if(this->initial->state->isGoal())
    {
        return Algorithms::BaseAlgorithm::createResponse(std::vector<Actions>(), this->expandedCount + 1);
    }

    open.push_back(this->initial);
    closed.insert(*(this->initial));
    while(!open.empty())
    {
        Node* node = open[0];
        expandedCount++;

        for(std::pair<const Actions, State*> &x : node->state->succ())
        {
            State* state = x.second;
            Actions action = x.first;
            Node* nextNode = Node::make_node(node, action, state);

            if(state->isGoal())
            {
                return Algorithms::BaseAlgorithm::createResponse(Node::extract_path(*nextNode, this->initial->state), expandedCount);
            }
            else if (!closed.count(*nextNode))
            {
                closed.insert(*nextNode);
                open.push_back(nextNode);
            }
        }
        open.pop_front();
    }

    throw Algorithms::UnsolvableProblem();
}