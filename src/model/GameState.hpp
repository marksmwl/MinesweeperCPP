#ifndef GAME_STATE_HEADER
#define GAME_STATE_HEADER

#include "MinesweeperBoard.hpp"
#include "MinesweeperCell.hpp"

class GameState
{
    MinesweeperBoard board;
    int boardMask[16][30];

public:
    GameState();
    bool leftClick(int, int);
    bool rightCLick(int, int);
    void reset();
    void getBoard(int outBoard[16][30]);
    void getEndBoard(int outBoard[16][30]);
    bool hasWon();
};

#endif