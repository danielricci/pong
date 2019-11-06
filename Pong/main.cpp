#include "Game.hpp"

int main(int argc, char** argv) {
    Game* game = new Game("Pong", 640, 480);
    game->startMainGameLoop();
    delete game;
}
