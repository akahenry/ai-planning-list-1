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
    std::vector<std::vector<int>> instances;
    std::vector<int> currentInstance;
    Algorithms::Types algorithm;

    for(int i = 1; i < argc; i++) 
    {
        switch(algorithm = Parser::hashit(argv[i])) 
        {
            case Algorithms::Types::NONE:
                try
                {
                    currentInstance.push_back(std::stoi(argv[i]));
                }
                catch(const std::invalid_argument& e)
                {
                    std::cerr << e.what() << '\n';
                    return NULL;
                }

                if(strchr(argv[i], ','))
                {
                    instances.push_back(currentInstance);
                    currentInstance.clear();
                } 
                break;
            default:
                continue;
        }
    }
    instances.push_back(currentInstance);

    return new Program{algorithm, instances};
}