#include "idfs.hpp"

std::pair<std::vector<Actions>, bool> Algorithms::IDFS::dls(Node* node, int depth)
{
    if(node->state->isGoal())
    {
        return std::pair<std::vector<Actions>, bool>(std::vector<Actions>(), true);
    }

    if(depth > 0)
    {
        for(Node* nextNode : BaseAlgorithm::adjacents(node))
        {
            std::pair<std::vector<Actions>, bool> solution = IDFS::dls(nextNode, depth - 1);

            if(solution.second)
            {
                solution.first.insert(solution.first.begin(), nextNode->action);
                return solution;
            }
        }
    }

    return std::pair<std::vector<Actions>, bool>(std::vector<Actions>(), false); 
}

Algorithms::Response Algorithms::IDFS::algorithm(State* state)
{
    for(int depth = 0; true; depth++)
    {
        std::pair<std::vector<Actions>, bool> solution = IDFS::dls(this->initial, depth);

        if(solution.second)
        {
            return this->createResponse(solution.first);
        }
    }
}