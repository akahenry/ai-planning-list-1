#include <iostream>
#include <string.h>
#include <vector>

enum Algorithms
{
    BFS,
    IDFS,
    ASTAR,
    IDASTAR,
    GBFS,
    NONE
};

Algorithms hashit(char* str) 
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


int main(int argc, char** argv) 
{
    std::vector<std::vector<int>> instances;
    std::vector<int> currentInstance;

    for(int i = 1; i < argc; i++) 
    {
        switch(hashit(argv[i])) 
        {
            case Algorithms::NONE:
                try
                {
                    currentInstance.push_back(std::stoi(argv[i]));
                }
                catch(const std::invalid_argument& e)
                {
                    std::cerr << e.what() << '\n';
                    return -1;
                }

                if(strchr(argv[i], ','))
                {
                    instances.push_back(currentInstance);
                    currentInstance.clear();
                } 
                break;
            case Algorithms::BFS:
                break;
            case Algorithms::IDFS:
                break;
            case Algorithms::ASTAR:
                break;
            case Algorithms::IDASTAR:
                break;
            case Algorithms::GBFS:
                break;
            default:
                break;
        }
    }
    instances.push_back(currentInstance);

    return 0;
}