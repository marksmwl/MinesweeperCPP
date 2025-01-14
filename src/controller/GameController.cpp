#include "GameController.hpp"
#include <iostream>

GameController::GameController(GameState *model) : model(model)
{
}

bool GameController::rightClickCell(int row, int col)
{
    return model->rightCLick(row, col);
}

bool GameController::LeftClickCell(int row, int col)
{
    return model->leftClick(row, col);
}

void GameController::start()
{
}

void GameController::restart()
{
}

int (&GameController::getState())[16][30]
{
    return model->getBoard();
}
