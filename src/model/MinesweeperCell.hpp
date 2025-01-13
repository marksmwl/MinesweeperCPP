#ifndef MINESWEEPER_CELL_HEADER
#define MINESWEEPER_CELL_HEADER

class MinesweeperCell
{
    bool hasBomb;
    int adjBombs;
    bool hasFlag;

public:
    bool setFlag();
    void setBomb();
    bool isBomb();
    int getAdjBombs();
    void incrementAdjBombs();
};

#endif