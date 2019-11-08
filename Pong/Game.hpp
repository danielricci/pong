#pragma once

#include <SDL.h>
#include "Paddle.hpp"

class Game {
  
public:
    Game(const char* title, int width, int height);
    ~Game();
    
    void startMainGameLoop();
    
private:
    
    Paddle* playerOne = { nullptr };
    Paddle* playerTwo = { nullptr };
    
    SDL_Window* window { nullptr };
    SDL_Renderer* windowRenderer { nullptr };
    
    bool isGameRunning { false };
    int framesPerSecond { 0 };
    
    void input();
    void update();
    void render();
    void updateFrameInformation();
};
