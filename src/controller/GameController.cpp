#include "GameController.hpp"
#include <iostream>

GameController::GameController(GameState *model) : model(model)
{
}

// Returns true if the cell is flagged, false if it is not.
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
    model->reset();
}

void GameController::getState(int outBoard[16][30])
{
    model->getBoard(outBoard);
}

void GameController::getEndBoard(int outBoard[16][30])
{
    model->getEndBoard(outBoard);
}

bool GameController::checkIfWon()
{
    return model->hasWon();
}
