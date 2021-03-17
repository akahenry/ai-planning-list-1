#include <iostream>

#include "bfsgraph.hpp"
#include "parser.hpp"

int main(int argc, char** argv) 
{
    Program* prog = Parser::parse(argc, argv);
    Algorithms::Response response;
    Algorithms::BaseAlgorithm* algorithm;

    for(int i = 0; i < prog->states.size(); i++)
    {
        switch(prog->algorithm)
        {
            case Types::BFS:
                algorithm = new Algorithms::BFSGraph();
                break;
            default:
                std::cout << prog->algorithm;
                break;
        }

    response = algorithm->run(&(prog->states[i]));
    std::cout << response.expandedNodes << ',' << response.optimalSolutionSize << ',' << 
                    response.elapsedTime << ',' << response.meanHeuristicFunction << ',' << 
                    response.initialHeuristicFunction << std::endl;
    }

    return 0;
}