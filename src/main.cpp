#include "parser.hpp"
#include "problem.hpp"

int main(int argc, char** argv) 
{
    Program* prog = Parser::parse(argc, argv);

    switch(prog->algorithm)
    {
        case Algorithms::BFS:
            for(int i = 0; i < prog->instances.size(); i++)
            {
                Algorithms::bfsGraph<std::vector<int>, Problem::Actions, double>(prog->instances[i]);
            }
            break;
    }

    return 0;
}