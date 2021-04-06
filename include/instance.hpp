/* instance.hpp
    Defines the class which will implement the Instance logic - which is the pratical concept of state.
    In this case, each instance represents a specific state in the game. Also, each state can be handle
    as a new instance (that's the reason for its name).
*/

#include <vector>
#include <map>
#include <algorithm> 
#include <math.h>

#include "actions.hpp"

#ifndef INSTANCE_H
#define INSTANCE_H

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

        std::map<Actions, int> ACTION_MOVE = {
            {Actions::UP, -std::sqrt(size)},
            {Actions::LEFT, -1},
            {Actions::RIGHT, 1},
            {Actions::DOWN, std::sqrt(size)}
        };

        Instance();
        Instance(std::vector<int> tiles, int blankTilePosition);
        int getBlankTilePosition();
        std::vector<int> getTiles();

        Instance nextInstance(Actions action);
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