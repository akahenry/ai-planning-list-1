#include <iostream>

#include "algorithms.hpp"
#include "parser.hpp"

int main(int argc, char** argv) 
{
    Program* prog = Parser::parse(argc, argv);

    switch(prog->algorithm)
    {
        case Types::BFS:
            for(int i = 0; i < prog->states.size(); i++)
            {
                
                Algorithms::Response response = Algorithms::bfsGraph(&(prog->states[i]));
                std::cout << response.expandedNodes << ',' << response.optimalSolutionSize << ',' << 
                    response.elapsedTime << ',' << response.meanHeuristicFunction << ',' << 
                    response.initialHeuristicFunction << std::endl;
            }
            break;
        default:
            std::cout << prog->algorithm;
            break;
    }

    return 0;
}