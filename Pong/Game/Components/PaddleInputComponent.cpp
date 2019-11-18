#include "PaddleInputComponent.hpp"

PaddleInputComponent::PaddleInputComponent(Paddle& paddle, SDL_Keycode upBinding, SDL_Keycode downBinding)
: InputComponent(paddle),
upBinding(upBinding),
downBinding(downBinding) {
}

void PaddleInputComponent::update(const SDL_Event& event) {
    switch(event.type) {
        case SDL_KEYDOWN: {
            SDL_Keycode keyCode = event.key.keysym.sym;
            if(keyCode == upBinding) {
                direction = Direction::UP;
            }
            else if(keyCode == downBinding) {
                direction = Direction::DOWN;
            }
            break;
        }
        case SDL_KEYUP: {
            SDL_Keycode keyCode = event.key.keysym.sym;
            if(keyCode == upBinding || keyCode == downBinding) {
                direction = Direction::NONE;
            }
            break;
        }
    }
}
