#include "Paddle.hpp"
#include <iostream>

Paddle::Paddle(int x, int y) {
    rectangle = new Rectangle(x, y, 5, 60);
}

Paddle::~Paddle() {
    delete rectangle;
}

void Paddle::input(const SDL_Event& event) {
    switch(event.type) {
        case SDL_KEYDOWN: {
            SDL_Keycode keyCode = event.key.keysym.sym;
            if(keyCode == upBinding) {
                orientationV = -1;
            }
            else if(keyCode == downBinding) {
                orientationV = 1;
            }
            break;
        }
        case SDL_KEYUP: {
            SDL_Keycode keyCode = event.key.keysym.sym;
            if(keyCode == upBinding || keyCode == downBinding) {
                orientationV = 0;
            }
            break;
        }
    }
}

void Paddle::update() {
    if(orientationV != 0) {
        rectangle->getRectangle()->y += (velocity * orientationV);
    }
}

void Paddle::render(SDL_Renderer& renderer) {
    SDL_RenderFillRect(&renderer, rectangle->getRectangle());
}
