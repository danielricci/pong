#pragma once

#include <SDL.h>

class Game {
public:
    Game(const char* title, int width, int height);
    ~Game();
    void run();
    
private:
    SDL_Window* window { nullptr };
    SDL_Renderer* renderer { nullptr };
};
