#include "MinesweeperBoard.hpp"
#include <cassert>

void MinesweeperBoard::setAdjacent(int row, int col)
{
    // +1  0  0
    // +1  B  0
    // +1  0  0
    if (col != 0)
    {
        cells[row][col - 1].incrementAdjBombs(); // Left
        if (row != 0)
            cells[row - 1][col - 1].incrementAdjBombs(); // Top left
        if (row != 15)
            cells[row + 1][col - 1].incrementAdjBombs(); // Bottom left
    }

    //  0 +1  0
    //  0  B  0
    //  0 +1  0
    if (row != 0 && row != 15)
    {
        cells[row - 1][col].incrementAdjBombs(); // Top
        cells[row + 1][col].incrementAdjBombs(); // Bottom
    }

    //  0  0 +1
    //  0  B +1
    //  0  0 +1
    if (col != 29)
    {
        cells[row][col + 1].incrementAdjBombs(); // Right
        if (row != 0)
            cells[row - 1][col + 1].incrementAdjBombs(); // Top right
        if (row != 15)
            cells[row + 1][col + 1].incrementAdjBombs(); // Bottom right
    }
}

void MinesweeperBoard::setBombs()
{
    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            if (rand() % 5 == 0)
            {
                cells[row][col].setBomb();
                setAdjacent(row, col);
            }
        }
    }
}

MinesweeperBoard::MinesweeperBoard()
{
    // Setup board and generate cells
    setBombs();
}

void MinesweeperBoard::reset()
{
    // Reset each cell to its default state
    for (int row = 0; row < 16; ++row)
    {
        for (int col = 0; col < 30; ++col)
        {
            cells[row][col] = MinesweeperCell(); // Reinitialize each cell
        }
    }
    setBombs();
}

bool MinesweeperBoard::rightClickCell(int, int)
{
    return 0;
}

bool MinesweeperBoard::leftClickCell(int row, int col)
{
    assert((row >= 0 && row <= 15) && (col >= 0 && col <= 29));

    if (cells[row][col].isBomb())
    {
        return true;
    }
    return false;
}

MinesweeperCell (&MinesweeperBoard::getBoard())[16][30]
{
    return cells;
}
