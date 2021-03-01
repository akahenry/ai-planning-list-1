#include "parser.hpp"
#include "actions.hpp"
#include "state.hpp"

int main(int argc, char** argv) 
{
    Program* prog = Parser::parse(argc, argv);

    switch(prog->algorithm)
    {
        case Algorithms::BFS:
            for(int i = 0; i < prog->states.size(); i++)
            {
                Algorithms::bfsGraph(prog->states[i]);
            }
            break;
    }

    return 0;
}