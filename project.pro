TEMPLATE = app
TARGET = MineSweeper
QT += widgets

# Add your source files here
SOURCES += src/main.cpp \
src/controller/GameController.cpp \
src/view/GameScreen.cpp \
src/view/MineSweeperCellButton.cpp \
src/model/GameState.cpp \
src/model/MinesweeperBoard.cpp \
src/model/MinesweeperCell.cpp
