#include "GameOverScreen.hpp"

GameOverScreen::GameOverScreen(QWidget *parent, GameController *GameController) : QDialog(parent), controller(GameController)
{
    // Remove window resizing, moving, and close button
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    // Set fixed size to prevent resizing
    setFixedSize(300, 200);

    // Set up the layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Add a label for the "YOU LOST" text
    QLabel *label = new QLabel("YOU LOST");
    label->setAlignment(Qt::AlignCenter);
    QFont font = label->font();
    font.setPointSize(24);
    font.setBold(true);
    label->setFont(font);
    layout->addWidget(label);

    // Add Replay button
    QPushButton *replayButton = new QPushButton("Replay");
    layout->addWidget(replayButton);

    // Add Quit button
    QPushButton *quitButton = new QPushButton("Quit");
    layout->addWidget(quitButton);

    // Connect buttons to their slots
    connect(replayButton, &QPushButton::clicked, this, &GameOverScreen::onReplayClicked);
    connect(quitButton, &QPushButton::clicked, this, &GameOverScreen::onQuitClicked);

    // Set layout and window title
    setLayout(layout);
    setWindowTitle("Game Over");
}

void GameOverScreen::closeEvent(QCloseEvent *event)
{
    // Ignore the close event
    return;
}

void GameOverScreen::moveEvent(QMoveEvent *event)
{
    // Prevent the dialog from being moved
    return;
}

void GameOverScreen::onReplayClicked()
{
    // Close the dialog and emit a signal to restart the game
    controller->restart();
    accept(); // Close the dialog
    emit replayRequested(false);
}

void GameOverScreen::onQuitClicked()
{
    // Quit the application
    qApp->quit();
}