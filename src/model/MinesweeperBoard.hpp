#ifndef MINESWEEPER_BOARD_HEADER
#define MINESWEEPER_BOARD_HEADER

#include "MinesweeperCell.hpp"
#include <cstdlib>
#include <chrono>
#include <thread>

class GameState;

class MinesweeperBoard
{
    MinesweeperCell cells[16][30];
    void setAdjacent(int, int);
    void setBombs();
    void reset();
    bool rightClickCell(int, int);
    bool leftClickCell(int, int, int (&mask)[16][30]);
    void sweep(int, int, int (&mask)[16][30]);
    MinesweeperCell (&getBoard())[16][30];

public:
    // Generates the board with the cells, will override existing cells.
    MinesweeperBoard();
    friend class GameState;
};

#endif