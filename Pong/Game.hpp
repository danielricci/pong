#ifndef Game_hpp
#define Game_hpp

#include <SDL.h>
#include "Paddle.hpp"

class Game {
  
public:
    Game(const char* title, int width, int height);
    ~Game();
    
    void startGame();
    
private:
    
    Paddle* playerOne = { nullptr };
    Paddle* playerTwo = { nullptr };
    
    SDL_Window* window { nullptr };
    SDL_Renderer* windowRenderer { nullptr };
    
    bool isGameRunning { false };
    
    void processGameInput();
    void processGameUpdate();
    void processGameRender();
};

#endif
