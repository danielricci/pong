#pragma once

#include "Game/Components/InputComponent.hpp"

#include <SDL.h>

#include <string>

class PaddleInputComponent : public InputComponent {
public:
    
    const std::string ACTION_MOVE_UP = "MoveUp";
    const std::string ACTION_MOVE_DOWN = "MoveDown";
    
    PaddleInputComponent();
    
private:
    void onMoveUp(const SDL_Event& event);
};
