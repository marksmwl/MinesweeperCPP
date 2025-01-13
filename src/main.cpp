#include <QApplication>
#include "controller/GameController.hpp"
#include "model/GameState.hpp"
#include "view/GameScreen.hpp"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    GameScreen view;
    GameState model;
    GameController gameController(&view, &model);

    view.show();
    return app.exec();
}