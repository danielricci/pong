#ifndef Player_hpp
#define Player_hpp

#include <SDL.h>

class Player {

public:
    Player();
    ~Player();
    
    void input(const SDL_Event& event);
    void update(float deltaTime);
    void render();
    
    SDL_Rect* getRectangle() const { return rectangle; }
    
private:
    SDL_Rect* rectangle = new SDL_Rect();
    const int velocity = 10;
};

#endif
