#ifndef Paddle_hpp
#define Paddle_hpp

#include "Rectangle.hpp"

class Paddle {
    
public:
    Paddle(int x, int y);
    ~Paddle();
    
    void setBindings(SDL_Keycode upBinding, SDL_Keycode downBinding) {
        this->upBinding = upBinding;
        this->downBinding = downBinding;
    }
    
    void input(const SDL_Event& event);
    void render(SDL_Renderer& renderer);
    void update();
    
private:
    
    SDL_Keycode upBinding { -1 };
    SDL_Keycode downBinding { -1 };
    
    int orientationV { 0 };
    const int velocity { 7 };
    
    Rectangle* rectangle { nullptr };
};

#endif
