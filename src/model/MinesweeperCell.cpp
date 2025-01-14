#include "MinesweeperCell.hpp"

void MinesweeperCell::setBomb()
{
    hasBomb = true;
}

bool MinesweeperCell::isBomb()
{
    return hasBomb;
}

int MinesweeperCell::getAdjBombs()
{
    if (hasBomb)
    {
        return -2;
    }
    return adjBombs;
}

void MinesweeperCell::incrementAdjBombs()
{
    adjBombs++;
}

bool MinesweeperCell::setFlag()
{
    hasFlag = !hasFlag;
    return hasFlag;
}
