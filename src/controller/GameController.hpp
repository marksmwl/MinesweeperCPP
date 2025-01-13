#ifndef GAME_CONTROLLER_HEADER
#define GAME_CONTROLLER_HEADER

#include "../view/GameScreen.hpp"
#include "../model/GameState.hpp"

class GameController
{
    GameScreen *view;
    GameState *model;

public:
    GameController(GameScreen *, GameState *);
    void cellRightClicked();
    void cellLeftClicked();
    static void start();
    void restart();
};

#endif