#include "Game.hpp"
#include "World.hpp"

#include <iostream>

Game::Game() : Application("Pong", 640, 480) { }

void Game::run() {
    World* world = new World(*window, *windowRenderer);
    world->run();
    delete world;
}
