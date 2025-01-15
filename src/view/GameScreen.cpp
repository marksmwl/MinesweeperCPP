#include "GameScreen.hpp"

// Method for communicating that the game has been lost
void GameScreen::endGame()
{
    player->setSource(QUrl("qrc:/assets/lose_minesweeper.wav"));
    player->play();

    GameOverScreen *gameOverScreen = new GameOverScreen(this, viewController);
    connect(gameOverScreen, &GameOverScreen::replayRequested, this, &GameScreen::render);
    gameOverScreen->exec();
    return;
}

void GameScreen::winGame()
{
    player->setSource(QUrl("qrc:/assets/win.wav"));
    player->play();
    render(true);
}

void GameScreen::render(bool hasEnded)
{
    if (!hasEnded && viewController->checkIfWon())
    {
        winGame();
        return;
    }
    static int board[16][30];

    if (hasEnded)
    {
        viewController->getEndBoard(board);
    }
    else
    {
        viewController->getState(board);
    }

    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            CellButton *cell = buttons[row][col];
            QString style;

            switch (board[row][col])
            {
            case -3: // Flag
                cell->setState(1);
                cell->setText("");
                break;
            case -2: // Bomb
                if (hasEnded)
                {
                    cell->setState(2);
                }
                else
                {
                    cell->setState(0);
                }
                cell->setText("");
                break;
            case -1: // Hidden cell
                cell->setState(0);
                cell->setText(""); // Clear any previous text
                break;

            default:               // Blank cells and numbered cells.
                cell->setText(""); // Clear any previous text
                cell->setState(board[row][col] + 3);
                break;
            }
        }
    }
}

GameScreen::GameScreen(QWidget *parent, GameController *controller)
    : QWidget(parent), viewController(controller)
{
    audioOutput = new QAudioOutput(this);
    player = new QMediaPlayer(this);

    // Connect the media player to the audio output
    player->setAudioOutput(audioOutput);

    // Set the volume (0.0 to 1.0)
    audioOutput->setVolume(0.5);

    player->setSource(QUrl("qrc:/assets/start.wav"));
    player->play();

    setWindowTitle("Minesweeper");
    setFixedSize(700, 400);

    gridLayout = new QGridLayout;
    int cellSize = 21;

    // Initialize the buttons vector
    buttons.resize(16);
    for (int row = 0; row < 16; ++row)
    {
        buttons[row].resize(30);
        for (int col = 0; col < 30; ++col)
        {
            CellButton *cell = new CellButton(this, row, col, viewController);
            cell->setStyleSheet("background-color: lightgray;");
            cell->setFixedSize(cellSize, cellSize);
            gridLayout->addWidget(cell, row, col);
            buttons[row][col] = cell; // Store the button pointer
            connect(cell, &CellButton::cellClicked, this, &GameScreen::onButtonClick);
        }
    }

    setLayout(gridLayout);
    render(false);
}

void GameScreen::onButtonClick(int row, int col)
{
    player->setSource(QUrl("qrc:/assets/click.wav"));
    player->play();

    if (row == -1)
    {
        render(true);
        endGame();
    }
    else
    {
        render(false);
    }
}