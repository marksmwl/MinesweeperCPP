#include "MinesweeperBoard.hpp"

void MinesweeperBoard::setAdjacent(int row, int col)
{
    if (row == 0)
    {
    }
    if (col == 0)
    {
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
}

void MinesweeperBoard::reset()
{
}

int MinesweeperBoard::rightClickCell(int, int)
{
    return 0;
}

int MinesweeperBoard::leftClickCell(int, int)
{
    return 0;
}
