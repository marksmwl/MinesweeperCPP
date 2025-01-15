#ifndef GAME_CONTROLLER_HEADER
#define GAME_CONTROLLER_HEADER

#include "../model/GameState.hpp"

class GameController
{
    GameState *model;

public:
    GameController(GameState *);
    bool rightClickCell(int, int);
    bool LeftClickCell(int, int);
    static void start();
    void restart();
    void getState(int outBoard[16][30]);
    void getEndBoard(int outBoard[16][30]);
    bool checkIfWon();
};

#endif