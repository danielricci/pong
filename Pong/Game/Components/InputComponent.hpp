#pragma once

#include <SDL.h>

class Paddle;

class InputComponent {
public:
    InputComponent(Paddle& paddle, SDL_Keycode upBinding, SDL_Keycode downBinding);
    void update(const SDL_Event& event);
private:
    enum class Direction {
        UP = -1,
        NONE,
        DOWN
    } direction { Direction:: NONE };
    
    SDL_Keycode upBinding { SDLK_UNKNOWN };
    SDL_Keycode downBinding { SDLK_UNKNOWN };
};
