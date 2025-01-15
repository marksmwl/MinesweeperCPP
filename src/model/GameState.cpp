#include "GameState.hpp"
#include <iostream>

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
    if (boardMask[row][col] == -3) // Dissalow user from clicking a flagged cell.
    {
        return false;
    }
    return board.leftClickCell(row, col, boardMask);
}

bool GameState::rightCLick(int row, int col)
{
    if (boardMask[row][col] != -1 && boardMask[row][col] != -3)
    {
        return false;
    }
    bool result = board.getBoard()[row][col].setFlag();
    if (result)
    {
        boardMask[row][col] = -3;
    }
    else // Reset the flag to an invisible cell to enable unflagging.
    {
        boardMask[row][col] = -1;
    }
    return result;
}

void GameState::reset()
{
    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            boardMask[row][col] = -1;
        }
    }
    board.reset();
}

// TODO FIX 480 METHOD CALLS
void GameState::getBoard(int outBoard[16][30])
{
    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            if (boardMask[row][col] == -1 || boardMask[row][col] == -3)
            {
                outBoard[row][col] = boardMask[row][col];
            }
            else
            {
                outBoard[row][col] = board.getBoard()[row][col].getAdjBombs();
            }
        }
    }
}

// TODO FIX 480 METHOD CALLS
void GameState::getEndBoard(int outBoard[16][30])
{
    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            outBoard[row][col] = board.getBoard()[row][col].getAdjBombs();
        }
    }
}

// A player is considered to have won if all non-bombs have been uncovered.
bool GameState::hasWon()
{
    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            // Check if the cell is still covered...
            if (boardMask[row][col] == -1 || boardMask[row][col] == -3)
            {
                // If it's covered, check if there's a bomb underneath.
                if (board.getBoard()[row][col].isBomb())
                {
                    continue; // If there is, then it doesn't count and we continue checking.
                }
                return false; // Otherwise, the player still has non-bombs to uncover.
            }
        }
    }

    return true; // We found no uncovered non-bombs, the player has won.
}
