#ifndef Paddle_hpp
#define Paddle_hpp

#include <SDL.h>
#include "Rectangle.hpp"

class Paddle {

public:
    Paddle();
    ~Paddle();
    
    void processInput(const SDL_Event& event);
    void update(float deltaTime);
    void render(SDL_Renderer* renderer);
    
    Rectangle* rectangle { nullptr };
    
private:

    const int velocity = 10;
};

#endif
