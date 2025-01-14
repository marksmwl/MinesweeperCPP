#ifndef MINESWEEPER_CELL_BUTTON_HEADER
#define MINESWEEPER_CELL_BUTTON_HEADER

#include <QWidget>
#include <QMouseEvent>
#include "../controller/GameController.hpp"
#include <iostream>

class CellButton : public QWidget
{
    int row;
    int col;
    GameController *viewController;

public:
    CellButton(QWidget *parent, int row, int col, GameController *viewController);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif