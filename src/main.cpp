#include <QApplication>
#include "controller/GameController.hpp"
#include "model/GameState.hpp"
#include "view/GameScreen.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    srand(time(0));
    QApplication app(argc, argv);

    GameScreen view;
    GameState model;
    GameController gameController(&view, &model);

    view.show();
    return app.exec();
}