#include "InputComponent.hpp"

InputComponent::InputComponent(Paddle& paddle, SDL_Keycode upBinding, SDL_Keycode downBinding)
: upBinding(upBinding),
downBinding(downBinding) {
}

void InputComponent::update(const SDL_Event& event) {
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
