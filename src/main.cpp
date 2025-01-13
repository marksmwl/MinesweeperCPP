#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Minesweeper");
    window.setFixedSize(800, 500);

    // Create a QGridLayout
    QGridLayout *gridLayout = new QGridLayout;

    // Size for each cell (e.g., 20x20 pixels)
    int cellSize = 20;

    // Loop through rows and columns to create a grid of square cells
    for (int row = 0; row < 16; ++row)
    {
        for (int col = 0; col < 30; ++col)
        {
            // Create a QLabel to represent each grid cell
            QPushButton *cell = new QPushButton();
            cell->setStyleSheet("background-color: lightgray;");
            cell->setFixedSize(cellSize, cellSize);

            // Add the cell to the grid at (row, col)
            gridLayout->addWidget(cell, row, col);
        }
    }

    // Set the layout of the window to the grid layout
    window.setLayout(gridLayout);

    window.show();
    return app.exec();
}