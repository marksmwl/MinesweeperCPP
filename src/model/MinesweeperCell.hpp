#ifndef MINESWEEPER_CELL_HEADER
#define MINESWEEPER_CELL_HEADER

class MinesweeperCell
{
    bool hasBomb;
    int adjBombs;
    bool hasFlag;

public:
    MinesweeperCell();
    bool setFlag();
    void setBomb();
    bool isBomb();
    int getAdjBombs();
    void incrementAdjBombs();
};

#endif