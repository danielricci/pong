#pragma once

#include "Engine/Components/InputComponent.hpp"

class Paddle;

class PaddleInputComponent : public InputComponent<Paddle> {
public:
    PaddleInputComponent(Paddle& paddle, SDL_Keycode upBinding, SDL_Keycode downBinding);
    virtual void update(const SDL_Event& event) override;
private:
    enum class Direction {
        UP = -1,
        NONE,
        DOWN
    } direction { Direction:: NONE };
    
    SDL_Keycode upBinding { SDLK_UNKNOWN };
    SDL_Keycode downBinding { SDLK_UNKNOWN };
};
