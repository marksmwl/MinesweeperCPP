#ifndef GAME_OVER_HEADER
#define GAME_OVER_HEADER

#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "../controller/GameController.hpp"

class GameScreen;

class GameOverScreen : public QDialog
{
    Q_OBJECT
    GameController *controller;

public:
    GameOverScreen(QWidget *parent = nullptr, GameController *gameController = nullptr);

protected:
    void closeEvent(QCloseEvent *event) override;
    void moveEvent(QMoveEvent *event) override;
signals:
    void replayRequested(bool);
private slots:
    void onReplayClicked();

    void onQuitClicked();
};

#endif