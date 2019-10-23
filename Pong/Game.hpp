#ifndef Game_hpp
#define Game_hpp

#include <SDL.h>
#include "Player.hpp"

class Game {
  
public:
    Game(const char* title, int width, int height);
    ~Game();
    void run();
    
private:
    const int width { 0 };
    const int height { 0 };
    bool running { false };
    
    SDL_Window* window { nullptr };
    SDL_Renderer* renderer { nullptr };
    Player* player = new Player();
    
    void input();
    void update();
    void render();
};

#endif
