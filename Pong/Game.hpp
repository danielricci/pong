#ifndef Game_hpp
#define Game_hpp

#include <SDL.h>

class Game {
  
public:
    Game(const char* title, int width, int height);
    ~Game();
    
    void startGame();
    
private:
    SDL_Window* window { nullptr };
    SDL_Renderer* renderer { nullptr };
    
    bool isGameRunning { false };
    
    void processGameInput();
    void processGameUpdate();
    void ProcessGameRender();
};

#endif
