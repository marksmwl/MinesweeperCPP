#include "MinesweeperCellButton.hpp"

CellButton::CellButton(QWidget *parent, int row, int col, GameController *controller)
    : QPushButton(parent), row(row), col(col), viewController(controller)
{
    if (viewController == nullptr)
    {
        std::cout << "Error: viewController is nullptr when passed to GameScreen constructor!" << std::endl;
    }
}

void CellButton::mousePressEvent(QMouseEvent *event)
{
    if (viewController == nullptr)
    {
        std::cerr << "viewController is nullptr!" << std::endl;
        return;
    }

    if (event->button() == Qt::LeftButton)
    {
        if (!viewController->LeftClickCell(row, col))
        {
            std::cout << "Bomb clicked\n";
        }
        emit cellClicked(row, col);
    }
    else if (event->button() == Qt::RightButton)
    {
        viewController->rightClickCell(row, col);
        emit cellClicked(row, col);
    }
}