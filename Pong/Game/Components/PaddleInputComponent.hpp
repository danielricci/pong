#pragma once

#include "Game/Components/InputComponent.hpp"

#include <SDL.h>

#include <string>

class PaddleInputComponent : public InputComponent {
public:
    PaddleInputComponent(SDL_Keycode keyUp, SDL_Keycode keyDown);
    
    int getDirection() const {
        return direction;
    }
    
private:
    const std::string ACTION_MOVE_UP = "MoveUp";
    const std::string ACTION_MOVE_DOWN = "MoveDown";
    
    int direction { 0 };
    
    void onMoveUp(const SDL_Event& event);
    void onMoveDown(const SDL_Event& event);
};
