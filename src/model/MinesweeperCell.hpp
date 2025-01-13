#ifndef MINESWEEPER_CELL_HEADER
#define MINESWEEPER_CELL_HEADER

class MinesweeperCell
{
    bool isBomb;
    int adjBombs;

public:
    int setBomb();
    void incrementAdjBombs();
};

#endif