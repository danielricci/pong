#ifndef Paddle_hpp
#define Paddle_hpp

#include "Rectangle.hpp"

class Paddle {
    
public:
    Paddle(int x, int y);
    ~Paddle();
    
    void input(const SDL_Event& event);
    void render(SDL_Renderer& renderer);
    void update();
    
private:
    
    int orientationV { 0 };
    const int velocity { 7 };
    
    Rectangle* rectangle { nullptr };
};

#endif
