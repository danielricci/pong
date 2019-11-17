#pragma once

#include "Engine/GameObject.hpp"
#include "Engine/Primitives/Rectangle.hpp"

class Paddle : public GameObject {

public:
    Paddle(int x, int y, SDL_Keycode upBinding, SDL_Keycode downBinding);
    ~Paddle();
        
    static void setMaximalHeight(int maximalHeight) {
        Paddle::maximalHeight = maximalHeight;
    }
    
    virtual void input(const SDL_Event& event) override;
    virtual void render(SDL_Renderer& renderer) override;
    virtual void update() override;
    
private:
    enum class Direction {
        UP = -1,
        NONE,
        DOWN
    } direction { Direction:: NONE };
    
    const int WIDTH { 5 };
    const int HEIGHT { 75 };
    const int VELOCITY { 5 };
    
    static int maximalHeight;
    
    SDL_Keycode upBinding { SDLK_UNKNOWN };
    SDL_Keycode downBinding { SDLK_UNKNOWN };
    
    Rectangle* rectangle { nullptr };
};
