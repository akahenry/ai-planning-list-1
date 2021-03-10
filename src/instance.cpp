#include "instance.hpp"

Instance::Instance()
{
    this->blankTilePosition = 0;
}

Instance::Instance(std::vector<int> tiles, int blankTilePosition)
{
    this->tiles = tiles;
    this->blankTilePosition = blankTilePosition;
}

int Instance::getBlankTilePosition()
{
    return this->blankTilePosition;
}

std::vector<int> Instance::getTiles()
{
    return std::vector<int>(this->tiles);
}

Instance* Instance::nextInstance(Actions action)
{
    std::vector<int> newTiles = this->tiles;
    int increment = 0;
    switch (this->blankTilePosition)
    {
    case 0:
        if (action == Actions::RIGHT || action == Actions::DOWN)
        {
            increment = Instance::ACTION_MOVE.at(action);
        }
        break;
    case 1:
        if (action == Actions::LEFT || action == Actions::RIGHT || action == Actions::DOWN)
        {
            increment = Instance::ACTION_MOVE.at(action);
        }
        break;
    case 2:
        if (action == Actions::LEFT || action == Actions::DOWN)
        {
            increment = Instance::ACTION_MOVE.at(action);
        }
        break;
    case 3:
        if (action == Actions::UP || action == Actions::RIGHT || action == Actions::DOWN)
        {
            increment = Instance::ACTION_MOVE.at(action);
        }
        break;
    case 4:
        increment = Instance::ACTION_MOVE.at(action);
        break;
    case 5:
        if (action == Actions::UP || action == Actions::LEFT || action == Actions::DOWN)
        {
            increment = Instance::ACTION_MOVE.at(action);
        }
        break;
    case 6:
        if (action == Actions::UP || action == Actions::RIGHT)
        {
            increment = Instance::ACTION_MOVE.at(action);
        }
        break;
    case 7:
        if (action == Actions::UP || action == Actions::LEFT || action == Actions::RIGHT)
        {
            increment = Instance::ACTION_MOVE.at(action);
        }
        break;
    case 8:
        if (action == Actions::UP || action == Actions::LEFT)
        {
            increment = Instance::ACTION_MOVE.at(action);
        }
        break;
    default:
        break;
    }

    if(increment == 0)
    {
        return this;
    }
    else 
    {
        newTiles[this->blankTilePosition] = this->tiles[this->blankTilePosition + increment];
        newTiles[this->blankTilePosition + increment] = 0;

        return new Instance(newTiles, this->blankTilePosition + increment);
    }
}

bool Instance::isGoal(Instance instance)
{
    return std::is_sorted(instance.tiles.begin(), instance.tiles.end());
}

Instance& Instance::operator=(const Instance &other)
{
    this->blankTilePosition = other.blankTilePosition;
    this->tiles = other.tiles;
    return *this;
}

bool Instance::operator==(const Instance &other)
{
    return (this->tiles == other.tiles) && (this->blankTilePosition == other.blankTilePosition);
}

std::size_t Instance::Instance_Hash::operator()(const Instance& instance) const
{
    std::vector<int> vec = instance.tiles;
    std::size_t seed = vec.size();
    for(auto& i : vec) {
        seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}