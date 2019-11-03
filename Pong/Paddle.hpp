#ifndef Paddle_hpp
#define Paddle_hpp

#include "Rectangle.hpp"

class Paddle {
    
public:
    Paddle(int x, int y);
    ~Paddle();
    
    void handleInput(const SDL_Event& event);
    void handleRender(SDL_Renderer& renderer);
    
private:
    const int WIDTH { 5 };
    const int HEIGHT { 60 };
    
    Rectangle* rectangle { nullptr };
};

#endif
