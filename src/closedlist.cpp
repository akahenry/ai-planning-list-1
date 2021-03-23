#include "closedlist.hpp"

template <typename State_Type, typename Node_Type> bool ClosedList<State_Type, Node_Type>::lookup(State_Type state)
{
    return this->find(state) != this->end();
}

template <typename State_Type, typename Node_Type> void ClosedList<State_Type, Node_Type>::insert(Node_Type node)
{
    this->insert({node.state, node});
}