#include "algorithms.hpp"


template <class State_Type, class Action_Type, typename T> void Algorithms::bfsGraph()
{
    OpenList<Node<State_Type, Action_Type, T>> open;
    ClosedList<State_Type, Node<State_Type, Action_Type, T>> closed;
    Node<State_Type, Action_Type, T> node;
    std::vector<ActionState<Action_Type, State_Type>> successors;

    open.insert(Node<State_Type, Action_Type, T>::make_root_node());

    while(!open.is_empty())
    {
        node = open.pop();

        if(!closed.lookup(node.state))
        {
            closed.insert(node);

            if(Algorithms::isGoal<typename State_Type>(node.state))
            {
                return Node<State_Type, Action_Type, T>::extract_path(node);
            }

            successors = Algorithms::succ<typename State_Type>(node.state);
            for(int i = 0; i < successors.size(); i++)
            {
                open.insert(Node<State_Type, Action_Type, T>::make_node(node, successors[i].action, successors[i].state));
            }
        }
    }

    throw Algorithms::UnsolvableProblem();
}