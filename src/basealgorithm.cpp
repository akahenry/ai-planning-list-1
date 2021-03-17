#include "basealgorithm.hpp"

Algorithms::Response Algorithms::BaseAlgorithm::run(State* state)
{
    this->startTime = std::chrono::high_resolution_clock::now();
    this->initial = Node::make_root_node(state);
    Algorithms::Response response = this->algorithm(state);
    this->endTime = std::chrono::high_resolution_clock::now();

    response.optimalSolutionSize = response.actionSequence.size();
    response.elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(this->endTime - this->startTime).count() / 1000000000.0;
    response.meanHeuristicFunction = this->heuristic.mean();
    response.initialHeuristicFunction = this->heuristic.run(*(this->initial->state));

    return response;
}

Algorithms::Response Algorithms::BaseAlgorithm::createResponse(std::vector<Actions> actions, int expandedNodes)
{
    Algorithms::Response response;

    response.actionSequence = actions;
    response.expandedNodes = expandedNodes;
    response.optimalSolutionSize = response.actionSequence.size();

    return response;
}