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
    // We have 480 cells, I will choose a max of 15% bombs for a medium difficulty (72 bombs)
    int bombsPlaced = 0;

    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            if (rand() % 5 == 0 && bombsPlaced < 72)
            {
                bombsPlaced++;
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

// Returns the value for the cell's flag.
bool MinesweeperBoard::rightClickCell(int row, int col)
{
    return cells[row][col].setFlag();
}

bool MinesweeperBoard::leftClickCell(int row, int col, int (&mask)[16][30])
{
    assert((row >= 0 && row <= 15) && (col >= 0 && col <= 29));

    if (cells[row][col].isBomb())
    {
        return true;
    }
    sweep(row, col, mask);
    return false;
}

void MinesweeperBoard::sweep(int row, int col, int (&mask)[16][30])
{
    if (row < 0 || row > 15 || col < 0 || col > 29)
    {
        return;
    }

    int bombNum = cells[row][col].getAdjBombs();
    if (bombNum > 0)
    {
        mask[row][col] = bombNum;
        return;
    }
    mask[row][col] = bombNum;

    sweep(row + 1, col, mask);
    sweep(row + 1, col + 1, mask);
    sweep(row + 1, col - 1, mask);

    sweep(row, col + 1, mask);
    sweep(row, col - 1, mask);

    sweep(row - 1, col, mask);
    sweep(row - 1, col + 1, mask);
    sweep(row - 1, col - 1, mask);
}

MinesweeperCell (&MinesweeperBoard::getBoard())[16][30]
{
    return cells;
}
