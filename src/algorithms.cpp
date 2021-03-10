#include "algorithms.hpp"

std::vector<Actions> Algorithms::bfsGraph(State* instance)
{
    State start = *instance;
    std::vector<Actions> result;
    std::deque<Node*> open;
    std::unordered_set<Node, Node::Node_Hash> closed;
    Node* root = Node::make_root_node(instance);

    if(start.isGoal())
        return result;

    open.push_back(root);
    closed.insert(*root);
    while(!open.empty())
    {
        Node* node = open[0];
        std::cout << "Closed size: " << closed.size() << std::endl;
        std::cout << "Open size: " << open.size() << std::endl;

        for(std::pair<const Actions, State*> &x : node->state->succ())
        {
            State* state = x.second;
            Actions action = x.first;
            Node* nextNode = Node::make_node(node, action, state);

            if(state->isGoal())
            {
                return Node::extract_path(*nextNode, &start);
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