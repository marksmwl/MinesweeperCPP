#ifndef MINESWEEPER_CELL_BUTTON_HEADER
#define MINESWEEPER_CELL_BUTTON_HEADER
#include <QWidget>
#include <QMouseEvent>
#include <QPushButton>
#include "../controller/GameController.hpp"
#include <iostream>
#include <QApplication>
#include <QPainter>
#include <QFile>
#include <QDir>
#include <QMediaPlayer>

class CellButton : public QPushButton // Change to QPushButton instead of QWidget
{
    Q_OBJECT

    int row;
    int col;
    GameController *viewController;
    int state; // Current state of the cell
    void loadImages();
    QString getImageForState(int state) const;

public:
    CellButton(QWidget *parent, int row, int col, GameController *viewController);
    void mousePressEvent(QMouseEvent *event) override;
    void setState(int newState);

signals:
    void cellClicked(int row, int col);

protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif