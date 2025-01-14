#ifndef GAME_SCREEN_HEADER
#define GAME_SCREEN_HEADER

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include "MinesweeperCellButton.hpp"
#include "../controller/GameController.hpp"

class GameScreen : public QWidget
{
    Q_OBJECT
private:
    GameController *viewController;
    void render();
    QGridLayout *gridLayout;
    QVector<QVector<CellButton *>> buttons; // Store buttons in a 2D vector

public:
    GameScreen(QWidget *parent, GameController *controller);

private slots:
    void onButtonClick(int row, int col);
};
#endif