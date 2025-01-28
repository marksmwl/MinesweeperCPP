TEMPLATE = app
TARGET = MineSweeper
QT += widgets
QT += multimedia

# Add your source files here
HEADERS += \
    src/controller/GameController.hpp \
    src/model/GameState.hpp \
    src/model/MinesweeperBoard.hpp \
    src/model/MinesweeperCell.hpp \
    src/view/GameScreen.hpp \
    src/view/MinesweeperCellButton.hpp \
    src/view/GameOverScreen.hpp

SOURCES += \
    src/main.cpp \
    src/controller/GameController.cpp \
    src/model/GameState.cpp \
    src/model/MinesweeperBoard.cpp \
    src/model/MinesweeperCell.cpp \
    src/view/GameScreen.cpp \
    src/view/MinesweeperCellButton.cpp \
    src/view/GameOverScreen.cpp
    

RESOURCES += resources.qrc

# Add these lines to ensure proper MOC handling
CONFIG += c++17
CONFIG += x11
