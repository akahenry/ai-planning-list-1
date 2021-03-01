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

Instance Instance::nextInstance(Actions action)
{
    std::vector<int> newTiles = this->tiles;
    int increment;
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
    newTiles[this->blankTilePosition] = this->tiles[this->blankTilePosition + increment];
    newTiles[this->blankTilePosition + increment] = 0;

    return Instance(newTiles, this->blankTilePosition + increment);
}

bool Instance::isGoal(Instance instance)
{
    return std::is_sorted(instance.tiles.begin(), instance.tiles.end());
}

Instance Instance::operator=(const Instance instance)
{
    return Instance(this->tiles, this->blankTilePosition);
}