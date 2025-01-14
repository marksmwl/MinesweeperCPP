#include "GameScreen.hpp"

void GameScreen::render()
{
    static int board[16][30];
    viewController->getState(board);

    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            CellButton *cell = buttons[row][col];
            QString style;

            switch (board[row][col])
            {
            case -1: // Hidden cell
                style = "background-color: pink;";
                cell->setText(""); // Clear any previous text
                break;

            case 0: // Empty revealed cell
                style = "background-color: white;";
                cell->setText(""); // Clear any previous text
                break;

            default: // Number cells
                style = QString("background-color: white; color: %1;")
                            .arg(board[row][col] == 1 ? "blue" : board[row][col] == 2 ? "green"
                                                             : board[row][col] == 3   ? "red"
                                                                                      : "black");
                cell->setText(QString::number(board[row][col]));
            }
            cell->setStyleSheet(style);
        }
    }
}

GameScreen::GameScreen(QWidget *parent, GameController *controller)
    : QWidget(parent), viewController(controller)
{
    setWindowTitle("Minesweeper");
    setFixedSize(700, 400);

    gridLayout = new QGridLayout;
    int cellSize = 22;

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
    render();
}

void GameScreen::onButtonClick(int row, int col)
{
    render();
}