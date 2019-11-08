#pragma once

#include "Rectangle.hpp"

class Paddle {
    
public:
    Paddle(int x, int y);
    ~Paddle();
    
    void setBindings(SDL_Keycode upBinding, SDL_Keycode downBinding) {
        this->upBinding = upBinding;
        this->downBinding = downBinding;
    }
    
    static void setMaximalHeight(int maximalHeight) {
        Paddle::maximalHeight = maximalHeight;
    }
    
    void input(const SDL_Event& event);
    void render(SDL_Renderer& renderer);
    void update();
    
private:
    enum class Direction {
        UP = -1,
        NONE,
        DOWN
    } direction { Direction:: NONE };
    
    const int WIDTH { 5 };
    const int HEIGHT { 60 };
    const int VELOCITY { 5 };
    
    static int maximalHeight;
    
    SDL_Keycode upBinding { SDLK_UNKNOWN };
    SDL_Keycode downBinding { SDLK_UNKNOWN };
    
    Rectangle* rectangle { nullptr };
};
