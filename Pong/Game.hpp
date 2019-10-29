#ifndef Game_hpp
#define Game_hpp

#include <SDL.h>
#include "Paddle.hpp"

class Game {
  
public:
    Game(const char* title, int width, int height);
    ~Game();
    void run();
    
private:
    const int width { 0 };
    const int height { 0 };
    bool running { false };
    float deltaTime { 0 };
    
    SDL_Window* window { nullptr };
    SDL_Renderer* renderer { nullptr };
    Paddle* paddle = new Paddle();
    
    void processInput();
    void update();
    void render();
};

#endif
