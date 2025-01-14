TEMPLATE = app
TARGET = MineSweeper
QT += widgets

# Add your source files here
HEADERS += \
    src/controller/GameController.hpp \
    src/model/GameState.hpp \
    src/model/MinesweeperBoard.hpp \
    src/model/MinesweeperCell.hpp \
    src/view/GameScreen.hpp \
    src/view/MinesweeperCellButton.hpp

SOURCES += \
    src/main.cpp \
    src/controller/GameController.cpp \
    src/model/GameState.cpp \
    src/model/MinesweeperBoard.cpp \
    src/model/MinesweeperCell.cpp \
    src/view/GameScreen.cpp \
    src/view/MinesweeperCellButton.cpp
    
# Add these lines to ensure proper MOC handling
CONFIG += c++17
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15