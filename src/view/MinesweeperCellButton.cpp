#include "MinesweeperCellButton.hpp"

CellButton::CellButton(QWidget *parent, int row, int col, GameController *controller) : QWidget(parent), row(row), col(col), viewController(controller)
{
    if (viewController == nullptr)
    {
        std::cout << "Error: viewController is nullptr when passed to GameScreen constructor!" << std::endl;
    }
    else
    {
        std::cout << "viewController is initialized." << std::endl;
    }
}

void CellButton::mousePressEvent(QMouseEvent *event)
{
    // Check if viewController is valid
    if (viewController == nullptr)
    {
        std::cerr << "viewController is nullptr!" << std::endl;
        return;
    }
    if (event->button() == Qt::LeftButton)
    {
        viewController->LeftClickCell(row, col);
        std::cout << "left clicked on" << row << std::endl;
    }
    else if (event->button() == Qt::RightButton)
    {
        viewController->rightClickCell(row, col);
        std::cout << "right clicked on" << std::endl;
    }
}