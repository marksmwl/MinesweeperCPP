#ifndef GAME_SCREEN_HEADER
#define GAME_SCREEN_HEADER

#include <QWidget>
#include <QGridLayout>
#include "MinesweeperCellButton.hpp"
#include "../controller/GameController.hpp"

class GameScreen : public QWidget
{
    GameController *viewController;

public:
    GameScreen(QWidget *parent, GameController *controller);
    // Rerender screen when a button is clicked.
    void onButtonClick();
};

#endif