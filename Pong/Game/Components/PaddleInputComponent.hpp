#pragma once

#include "Game/Components/InputComponent.hpp"

#include <SDL.h>

#include <string>

class PaddleInputComponent : public InputComponent {
public:
    inline static const std::string ACTION_MOVE_UP = "MoveUp";
    inline static const std::string ACTION_MOVE_DOWN = "MoveDown";
    
    PaddleInputComponent();
    
    int getDirection() const {
        return direction;
    }
    
private:
    
    int direction { 0 };
    
    void onMoveUp(const SDL_Event& event);
    void onMoveDown(const SDL_Event& event);
};
