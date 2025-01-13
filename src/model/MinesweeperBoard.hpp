#ifndef MINESWEEPER_BOARD_HEADER
#define MINESWEEPER_BOARD_HEADER

#include "MinesweeperCell.hpp"
#include <cstdlib>

class MinesweeperBoard
{
    MinesweeperCell cells[16][30];
    void setAdjacent(int, int);
    void setBombs();
    void placeCells();

public:
    // Generates the board with the cells, will override existing cells.
    MinesweeperBoard();
    void reset();
    bool rightClickCell(int, int);
    bool leftClickCell(int, int);
    MinesweeperCell (&getBoard())[16][30];
};

#endif