#include "Game/GameWindow.hpp"

#include <SDL.h>

int main(int argc, char** argv) {
    GameWindow("Pong", 640, 800).show();
}
