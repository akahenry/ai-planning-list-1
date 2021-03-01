#include "parser.hpp"

Algorithms::Types Parser::hashit(char* str) 
{
    if(!strcmp(str, "-bfs"))
        return Algorithms::BFS;
    else if(!strcmp(str, "-idfs"))
        return Algorithms::IDFS;
    else if(!strcmp(str, "-astar"))
        return Algorithms::ASTAR;
    else if(!strcmp(str, "-idastar"))
        return Algorithms::IDASTAR;
    else if(!strcmp(str, "-gbfs"))
        return Algorithms::GBFS;
    else
        return Algorithms::NONE;
}

Program* Parser::parse(int argc, char** argv)
{
    std::vector<State> states;
    std::vector<int> currentInstance;
    int currentBlankTilePosition;
    Algorithms::Types algorithm;

    for(int i = 1; i < argc; i++) 
    {
        switch(algorithm = Parser::hashit(argv[i])) 
        {
            case Algorithms::Types::NONE:
                try
                {
                    int temp = std::stoi(argv[i]);
                    currentInstance.push_back(temp);
                    if (temp == 0)
                    {
                        currentBlankTilePosition = currentInstance.size() - 1;
                    }
                }
                catch(const std::invalid_argument& e)
                {
                    std::cerr << e.what() << '\n';
                    return NULL;
                }

                if(strchr(argv[i], ','))
                {
                    states.push_back(State(Instance(currentInstance, currentBlankTilePosition)));
                    currentInstance.clear();
                } 
                break;
            default:
                continue;
        }
    }
    states.push_back(State(Instance(currentInstance, currentBlankTilePosition)));

    return new Program{algorithm, states};
}