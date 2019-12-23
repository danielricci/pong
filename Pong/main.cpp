#include "Game/Game.hpp"

int main(int argc, char** argv) {
    Game* game = new Game("Pong", 640, 480);
    if(game->ready) {
        game->run();
    }
    delete game;
}

/*
 else {
     TTF_Font* font = TTF_OpenFont("Resources/Fonts/Verdana.ttf", 16);
 */
