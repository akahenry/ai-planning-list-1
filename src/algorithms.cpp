#include "algorithms.hpp"

int Algorithms::heuristic(Node node)
{
    int result = 1;

    Algorithms::heuristicCount++;
    Algorithms::heuristicAcc += result;

    return result; //#TODO
}

Algorithms::Response Algorithms::createResponse(Node initial, std::vector<Actions> actions, std::chrono::_V2::system_clock::time_point startPoint, int expandedNodes, Heuristic heuristic)
{
    Algorithms::Response response;
    std::chrono::_V2::system_clock::time_point stopPoint = std::chrono::high_resolution_clock::now();

    response.actionSequence = actions;
    response.expandedNodes = expandedNodes;
    response.optimalSolutionSize = response.actionSequence.size();
    response.elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(stopPoint - startPoint).count() / 1000000000.0;
    response.meanHeuristicFunction = heuristic.mean();
    response.initialHeuristicFunction = heuristic.run(*(initial.state));

    return response;
}

Algorithms::Response Algorithms::bfsGraph(State* instance)
{
    std::chrono::_V2::system_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    Heuristic heuristic = Heuristic();
    State start = *instance;
    Algorithms::Response response;
    std::deque<Node*> open;
    std::unordered_set<Node, Node::Node_Hash> closed;
    Node* root = Node::make_root_node(instance);

    if(start.isGoal())
    {
        response = Algorithms::createResponse(*root, std::vector<Actions>(), startTime, closed.size() + 1, heuristic);

        return response;
    }

    open.push_back(root);
    closed.insert(*root);
    while(!open.empty())
    {
        Node* node = open[0];

        for(std::pair<const Actions, State*> &x : node->state->succ())
        {
            State* state = x.second;
            Actions action = x.first;
            Node* nextNode = Node::make_node(node, action, state);

            if(state->isGoal())
            {
                response = Algorithms::createResponse(*root, Node::extract_path(*nextNode, &start), startTime, closed.size() + 1, heuristic);

                return response;
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