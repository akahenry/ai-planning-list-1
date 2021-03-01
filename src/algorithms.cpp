#include "algorithms.hpp"

std::vector<Actions> Algorithms::bfsGraph(State instance)
{
    OpenList<Node<State, Actions, double>> open;
    ClosedList<State, Node<State, Actions, double>> closed;
    Node<State, Actions, double> node;
    std::vector<ActionState> successors;

    open.insert(Node<State, Actions, double>::make_root_node());

    while(!open.is_empty())
    {
        node = open.pop();

        if(!closed.lookup(*(node.state)))
        {
            closed.insert(node);

            if(Algorithms::isGoal(*(node.state)))
            {
                return Node<State, Actions, double>::extract_path(node);
            }

            successors = Algorithms::succ(*(node.state));
            for(int i = 0; i < successors.size(); i++)
            {
                open.insert(Node<State, Actions, double>::make_node(&node, successors[i].action, &(successors[i].state)));
            }
        }
    }

    throw Algorithms::UnsolvableProblem();
}