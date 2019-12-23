#pragma once

#include "Game/World.hpp"

#include <SDL.h>

class Game {
public:
    Game(const char* title, int width, int height);
    ~Game();
    void run();
  
    bool ready { false };
    
private:
    SDL_Window* window { nullptr };
    SDL_Renderer* renderer { nullptr };
    World* world { nullptr };
};
