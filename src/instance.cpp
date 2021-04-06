#include "instance.hpp"

Instance::Instance()
{
    this->blankTilePosition = 0;
    this->size = 0;
}

Instance::Instance(std::vector<int> tiles, int blankTilePosition)
{
    this->tiles = tiles;
    this->blankTilePosition = blankTilePosition;
    this->size = tiles.size();
    this->ACTION_MOVE[Actions::UP] = -std::sqrt(this->size);
    this->ACTION_MOVE[Actions::DOWN] = std::sqrt(this->size);
}

int Instance::getBlankTilePosition()
{
    return this->blankTilePosition;
}

std::vector<int> Instance::getTiles()
{
    return std::vector<int>(this->tiles);
}

Instance Instance::nextInstance(Actions action)
{
    std::vector<int> newTiles = this->tiles;
    int increment = 0;
    const int sqrtSize = std::sqrt(this->size);

    int xBlankTilePosition = this->blankTilePosition/sqrtSize;
    int yBlankTilePosition = this->blankTilePosition%sqrtSize;

    if(xBlankTilePosition == 0)
    {
        if(action == Actions::UP)
        {
            return *this;
        }
    }
    else if (xBlankTilePosition == (sqrtSize - 1))
    {
        if(action == Actions::DOWN)
        {
            return *this;
        }
    }

    if(yBlankTilePosition == 0)
    {
        if(action == Actions::LEFT)
        {
            return *this;
        }
    }
    else if (yBlankTilePosition == (sqrtSize - 1))
    {
        if(action == Actions::RIGHT)
        {
            return *this;
        }
    }

    increment = this->ACTION_MOVE.at(action);
    newTiles[this->blankTilePosition] = this->tiles[this->blankTilePosition + increment];
    newTiles[this->blankTilePosition + increment] = 0;

    return Instance(newTiles, this->blankTilePosition + increment);
}

bool Instance::isGoal(Instance instance)
{
    return std::is_sorted(instance.tiles.begin(), instance.tiles.end());
}

Instance& Instance::operator=(const Instance &other)
{
    this->blankTilePosition = other.blankTilePosition;
    this->tiles = other.tiles;
    this->size = other.size;
    this->ACTION_MOVE = other.ACTION_MOVE;
    return *this;
}

bool Instance::operator==(const Instance &other)
{
    return (this->tiles == other.tiles) && (this->blankTilePosition == other.blankTilePosition);
}

unsigned long base2dec(int b, std::vector<int> vec)
{
    unsigned long digit;           // Current digit
    unsigned long ret = 0;         // The return value

    // Continue until the end of the string is reached
    for (int& p : vec)
    {
        ret = ret * b + p;
    }
    return ret;
}

std::size_t Instance::Instance_Hash::operator()(const Instance& instance) const
{
    std::vector<int> vec = instance.tiles;
    std::size_t idx = base2dec(instance.size, vec);

    return idx;
}

