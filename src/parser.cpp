#include "parser.hpp"

Types Parser::hashit(char* str) 
{
    if(!strcmp(str, "-bfs"))
        return Types::BFS;
    else if(!strcmp(str, "-idfs"))
        return Types::IDFS;
    else if(!strcmp(str, "-astar"))
        return Types::ASTAR;
    else if(!strcmp(str, "-idastar"))
        return Types::IDASTAR;
    else if(!strcmp(str, "-gbfs"))
        return Types::GBFS;
    else
        return Types::NONE;
}

Program* Parser::parse(int argc, char** argv)
{
    std::vector<State*> states;
    std::vector<int> currentInstance;
    int currentBlankTilePosition = 0;
    Types temp;
    Types algorithm;

    for(int i = 1; i < argc; i++) 
    {
        temp = Parser::hashit(argv[i]);
        switch(temp) 
        {
            case Types::NONE:
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
                    states.push_back(new State(Instance(currentInstance, currentBlankTilePosition)));
                    currentInstance.clear();
                } 
                break;
            default:
                algorithm = temp;
                continue;
        }
    }
    states.push_back(new State(Instance(currentInstance, currentBlankTilePosition)));

    return new Program{algorithm, states};
}