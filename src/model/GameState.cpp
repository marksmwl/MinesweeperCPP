#include "GameState.hpp"

GameState::GameState()
{
    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            boardMask[row][col] = -1;
        }
    }
}

// Returns true if the user clicked a bomb, false otherwise
bool GameState::leftClick(int row, int col)
{
    return board.leftClickCell(row, col, boardMask);
}

bool GameState::rightCLick(int row, int col)
{
    return board.getBoard()[row][col].setFlag();
}

void GameState::reset()
{
    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            boardMask[row][col] = 1;
        }
    }
    board.reset();
}

void GameState::getBoard(int outBoard[16][30])
{
    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            if (boardMask[row][col] == -1)
            {
                outBoard[row][col] = -1;
            }
            else
            {
                outBoard[row][col] = board.getBoard()[row][col].getAdjBombs();
            }
        }
    }
}
