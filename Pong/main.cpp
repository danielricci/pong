#include "Game/GameWindow.hpp"

int main(int argc, char** argv) {
    GameWindow* game = new GameWindow("Pong", 640, 480);
    game->show();
    delete game;
}
