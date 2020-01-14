#include "PaddleInputComponent.hpp"

//#include <iostream>

PaddleInputComponent::PaddleInputComponent(SDL_Keycode keyUp, SDL_Keycode keyDown) {
    this->addBindings(keyUp, ACTION_MOVE_UP);
    this->addBindings(keyDown, ACTION_MOVE_DOWN);

    registerActionBinding(ACTION_MOVE_UP, std::bind(&PaddleInputComponent::onMoveUp, this, std::placeholders::_1));
    registerActionBinding(ACTION_MOVE_DOWN, std::bind(&PaddleInputComponent::onMoveDown, this, std::placeholders::_1));
}

void PaddleInputComponent::onMoveUp(const SDL_Event& event) {
    switch(event.type) {
        case SDL_KEYDOWN:
            direction = -1;
            break;
        default:
            direction = 0;
            break;
    }
    
    //std::cout << "Direction = " << direction << std::endl;
}

void PaddleInputComponent::onMoveDown(const SDL_Event& event) {
    switch(event.type) {
        case SDL_KEYDOWN:
            direction = 1;
            break;
        default:
            direction = 0;
            break;
    }
    
    //std::cout << "Direction = " << direction << std::endl;
}
