#include <vector>
#include <map>
#include <algorithm> 

#include "actions.hpp"

#ifndef INSTANCE_H
#define INSTANCE_H

// TODO: doesnt work with 15-puzzle

class Instance
{
    private:
        std::vector<int> tiles;
        int blankTilePosition;
        int size;

    public:
        struct Instance_Hash
        {
            std::size_t operator()(const Instance& instance) const;
        };

        const std::map<Actions, int> ACTION_MOVE = {
            {Actions::UP, -3},
            {Actions::LEFT, -1},
            {Actions::RIGHT, 1},
            {Actions::DOWN, 3}
        };

        Instance();
        Instance(std::vector<int> tiles, int blankTilePosition);
        int getBlankTilePosition();
        std::vector<int> getTiles();

        Instance* nextInstance(Actions action);
        static bool isGoal(Instance instance);

        Instance& operator=(const Instance &other);
        bool operator==(const Instance &other);
};

template <>
struct std::hash<Instance>
{
    std::size_t operator()(const Instance& instance) const;
};

#endif