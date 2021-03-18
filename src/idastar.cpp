#include "idastar.hpp"

std::pair<Algorithms::IntOrNone, Algorithms::ActionsOrNone> Algorithms::IDAStar::recursiveSearch(Node* node, int limit)
{
    int f_n = node->path_cost + this->heuristic.run(*(node->state));

    if(f_n > limit)
    {
        return std::pair<Algorithms::IntOrNone, Algorithms::ActionsOrNone>(Algorithms::IntOrNone{f_n, false}, Algorithms::ActionsOrNone{std::vector<Actions>(), true});
    }

    if(node->state->isGoal())
    {
        return std::pair<Algorithms::IntOrNone, Algorithms::ActionsOrNone>(Algorithms::IntOrNone{0, true}, Algorithms::ActionsOrNone{Node::extract_path(*node, this->initial->state), false});
    }

    int nextLimit = std::numeric_limits<int>::max();

    for(Node* nextNode : BaseAlgorithm::adjacents(node))
    {
        std::pair<Algorithms::IntOrNone, Algorithms::ActionsOrNone> result = this->recursiveSearch(nextNode, limit);

        if(!result.second.isNone)
        {
            return std::pair<Algorithms::IntOrNone, Algorithms::ActionsOrNone>(Algorithms::IntOrNone{0, true}, result.second);
        }

        nextLimit = std::min<int>(nextLimit, result.first.value);
    }

    return std::pair<Algorithms::IntOrNone, Algorithms::ActionsOrNone>(Algorithms::IntOrNone{nextLimit, false}, Algorithms::ActionsOrNone{std::vector<Actions>(), true});
}

Algorithms::Response Algorithms::IDAStar::algorithm(State* state)
{
    int limit = this->heuristic.run(*state);

    while(limit <= std::numeric_limits<int>::max())
    {   
        std::pair<Algorithms::IntOrNone, Algorithms::ActionsOrNone> result = this->recursiveSearch(this->initial, limit);

        if(!result.second.isNone)
        {
            return this->createResponse(result.second.actions);
        }
    }

    throw Algorithms::UnsolvableProblem();
}