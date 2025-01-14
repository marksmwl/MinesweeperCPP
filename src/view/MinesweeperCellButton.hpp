#ifndef MINESWEEPER_CELL_BUTTON_HEADER
#define MINESWEEPER_CELL_BUTTON_HEADER
#include <QWidget>
#include <QMouseEvent>
#include <QPushButton>
#include "../controller/GameController.hpp"
#include <iostream>

class CellButton : public QPushButton // Change to QPushButton instead of QWidget
{
    Q_OBJECT
private:
    int row;
    int col;
    GameController *viewController;

public:
    CellButton(QWidget *parent, int row, int col, GameController *viewController);
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void cellClicked(int row, int col);
};
#endif