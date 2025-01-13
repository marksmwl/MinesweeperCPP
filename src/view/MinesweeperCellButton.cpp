#include "MinesweeperCellButton.hpp"

CellButton::CellButton(QWidget *parent, Cell cell) : QWidget(parent)
{
    this->cell = cell;
}

void CellButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
    }
    else if (event->button() == Qt::RightButton)
    {
    }
}