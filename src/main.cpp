#include <QApplication>
#include "controller/GameController.hpp"
#include "model/GameState.hpp"
#include "view/GameScreen.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    srand(time(0));
    QApplication app(argc, argv);

    GameState model;
    GameController gameController(&model);
    GameScreen view(nullptr, &gameController);

    view.show();
    return app.exec();
}