#include "MinesweeperBoard.hpp"
#include <cassert>
#include <iostream>

// TODO: FIX
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
    // We have 480 cells, I will choose a max of 10% bombs for a easy difficulty (48 bombs)
    int bombsPlaced = 0;

    while (bombsPlaced < 48)
    {
        int row = rand() % 16;
        int col = rand() % 30;

        if (cells[row][col].isBomb())
        {
            continue;
        }
        cells[row][col].setBomb();
        bombsPlaced++;
        setAdjacent(row, col);
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

    // Add check to prevent infinite recursion
    if (row < 0 || row > 15 || col < 0 || col > 29 || mask[row][col] != -1)
    {
        return;
    }

    int bombNum = cells[row][col].getAdjBombs();
    mask[row][col] = bombNum; // Update mask before recursion

    // Only recurse if this is a zero cell
    if (bombNum == 0)
    {
        sweep(row + 1, col, mask);
        // sweep(row + 1, col + 1, mask);
        // sweep(row + 1, col - 1, mask);
        sweep(row, col + 1, mask);
        sweep(row, col - 1, mask);
        sweep(row - 1, col, mask);
        // sweep(row - 1, col + 1, mask);
        // sweep(row - 1, col - 1, mask);
    }
}

MinesweeperCell (&MinesweeperBoard::getBoard())[16][30]
{
    for (int row = 0; row < 16; row++)
    {
        std::cout << '\n';
        for (int col = 0; col < 30; col++)
        {
            std::cout << cells[row][col].getAdjBombs() << " ";
        }
    }
    std::cout << '\n\n';
    return cells;
}
