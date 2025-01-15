#ifndef GAME_SCREEN_HEADER
#define GAME_SCREEN_HEADER

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include "MinesweeperCellButton.hpp"
#include "../controller/GameController.hpp"
#include <QLabel>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "GameOverScreen.hpp"

class GameScreen : public QWidget
{
    Q_OBJECT
private:
    QMediaPlayer *player = nullptr;
    QAudioOutput *audioOutput = nullptr;
    GameController *viewController;
    void endGame();
    QGridLayout *gridLayout;
    QVector<QVector<CellButton *>> buttons; // Store buttons in a 2D vector
    void winGame();

public:
    GameScreen(QWidget *parent, GameController *controller);

private slots:
    void render(bool);
    void onButtonClick(int row, int col);
};
#endif