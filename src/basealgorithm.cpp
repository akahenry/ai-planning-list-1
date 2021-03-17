#include "basealgorithm.hpp"

Algorithms::Response Algorithms::BaseAlgorithm::run(State* state)
{
    this->startTime = std::chrono::high_resolution_clock::now();
    this->initial = Node::make_root_node(state);
    Algorithms::Response response = this->algorithm(state);
    this->endTime = std::chrono::high_resolution_clock::now();

    response.expandedNodes = this->expandedCount;
    response.optimalSolutionSize = response.actionSequence.size();
    response.elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(this->endTime - this->startTime).count() / 1000000000.0;
    response.meanHeuristicFunction = this->heuristic.mean();
    response.initialHeuristicFunction = this->heuristic.run(*(this->initial->state));

    return response;
}

Algorithms::Response Algorithms::BaseAlgorithm::createResponse(std::vector<Actions> actions)
{
    Algorithms::Response response;

    response.actionSequence = actions;
    response.optimalSolutionSize = response.actionSequence.size();

    return response;
}

std::vector<Node*> Algorithms::BaseAlgorithm::adjacents(Node* node)
{
    std::vector<Node*> response;

    for(std::pair<const Actions, State*> &x : node->state->succ())
    {
        Actions action = x.first;
        State* state = x.second;
        if(state->instance->getBlankTilePosition() != node->state->instance->getBlankTilePosition())
        {
            response.push_back(Node::make_node(node, action, state));
        }
    }
    
    return response;
}