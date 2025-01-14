#include "GameScreen.hpp"

GameScreen::GameScreen(QWidget *parent, GameController *controller) : QWidget(parent), viewController(controller)
{
    std::cout << "viewController in GameScreen: " << viewController << std::endl;

    setWindowTitle("Minesweeper");
    setFixedSize(800, 500);

    // Create a QGridLayout
    QGridLayout *gridLayout = new QGridLayout;

    // Size for each cell (e.g., 20x20 pixels)
    int cellSize = 20;

    // Loop through rows and columns to create a grid of square cells
    for (int row = 0; row < 16; ++row)
    {
        for (int col = 0; col < 30; ++col)
        {
            if (viewController == nullptr)
            {
                std::cout << "nullptr!" << std::endl;
            }
            // Create a QLabel to represent each grid cell
            CellButton *cell = new CellButton(this, row, col, viewController);
            cell->setStyleSheet("background-color: lightgray;");
            cell->setFixedSize(cellSize, cellSize);

            // Add the cell to the grid at (row, col)
            gridLayout->addWidget(cell, row, col);
        }
    }

    // Set the layout of the window to the grid layout
    setLayout(gridLayout);
}

// Rerender screen when a button is clicked.
void GameScreen::onButtonClick()
{
}
