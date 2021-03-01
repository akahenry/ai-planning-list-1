#include "graph.hpp"

template <class State_Type, class Action_Type, typename T> Node<State_Type, Action_Type, T> Node<State_Type, Action_Type, T>::make_root_node()
{
    Node node = new Node;
    node->state = new State_Type;
    node->parent = NULL;
    node->action = NULL;
    node->path_cost = 0;

    return node;
}

template <class State_Type, class Action_Type, typename T> Node<State_Type, Action_Type, T> Node<State_Type, Action_Type, T>::make_node(Node<State_Type, Action_Type, T>* parent, Action_Type action, State_Type* state)
{
    Node node = new Node;
    node->state = state;
    node->parent = parent;
    node->action = action;
    node->path_cost = parent.path_cost + action.cost();

    return node;
}

template <class State_Type, class Action_Type, typename T> std::vector<Action_Type> Node<State_Type, Action_Type, T>::extract_path(Node<State_Type, Action_Type, T> node)
{
    std::vector<Action_Type> path;

    while(node.parent)
    {
        path.push_back(node.action);
        node = node.parent;
    }

    std::reverse(path.begin(), path.end());

    return path;
}

template <typename T> bool OpenList<T>::is_empty()
{
    return this->empty();
}

template <typename T> T OpenList<T>::pop()
{
    return this->pop();
}

template <typename T> void OpenList<T>::insert(T node)
{
    this->push_back(node);
}

template <typename State_Type, typename Node_Type> bool ClosedList<State_Type, Node_Type>::lookup(State_Type state)
{
    return this->find(state) != this->end();
}

template <typename State_Type, typename Node_Type> void ClosedList<State_Type, Node_Type>::insert(Node_Type node)
{
    this->insert({node->state, node});
}