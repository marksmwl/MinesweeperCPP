#ifndef MINESWEEPER_CELL_BUTTON_HEADER
#define MINESWEEPER_CELL_BUTTON_HEADER

#include <QWidget>
#include <QMouseEvent>
#include "../logic/MinesweeperCell.hpp"

class CellButton : public QWidget
{
    Cell cell;

public:
    CellButton(QWidget *parent, Cell cell);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif