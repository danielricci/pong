#include "PaddleInputComponent.hpp"

#include <iostream>

PaddleInputComponent::PaddleInputComponent() {
    registerActionBinding(ACTION_MOVE_UP, std::bind(&PaddleInputComponent::onMoveUp, this, std::placeholders::_1));
}


void PaddleInputComponent::onMoveUp(const SDL_Event& event) {
    
}
