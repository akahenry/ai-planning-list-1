#include <vector>
#include <map>
#include <algorithm> 

#include "actions.hpp"

#ifndef INSTANCE_H
#define INSTANCE_H

class Instance
{
    private:
        std::vector<int> tiles;
        //int blankTilePosition;

    public:
        int blankTilePosition;

        const std::map<Actions, int> ACTION_MOVE = {
            {Actions::UP, -3},
            {Actions::LEFT, -1},
            {Actions::RIGHT, 1},
            {Actions::DOWN, 3}
        };

        Instance();
        Instance(std::vector<int> tiles, int blankTilePosition);
        Instance* nextInstance(Actions action);
        static bool isGoal(Instance instance);

        Instance& operator=(const Instance &other);
        bool operator==(const Instance &other);
};

#endif