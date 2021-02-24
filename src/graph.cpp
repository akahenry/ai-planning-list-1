#include <cstddef>

template <class State_Type, class Action_Type, typename T = int> class Node
{
    public:
        State_Type* state;
        Node* parent;
        Action_Type* action;
        T path_cost;

        Node make_root_node()
        {
            Node node = new Node;
            node->state = new State_Type;
            node->parent = NULL;
            node->action = NULL;
            node->path_cost = 0;

            return node;
        }

        Node make_node(Node parent, Action_Type action, State_Type state)
        {
            Node node = new Node;
            node.state = state;
            node.parent = parent;
            node.action = action;
            node->path_cost = parent.path_cost + action.cost();

            return node;
        }
};