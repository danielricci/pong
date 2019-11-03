#include "Paddle.hpp"
#include <iostream>

Paddle::Paddle(int x, int y) {
    rectangle = new Rectangle(x, y, WIDTH, HEIGHT);
}

Paddle::~Paddle() {
    delete rectangle;
}

void Paddle::handleInput(const SDL_Event& event) {
    switch(event.type) {
        case SDL_KEYUP: {
            switch(event.key.keysym.sym) {
                case SDLK_UP: {
                    break;
                }
            }
            break;
        }
        case SDL_KEYDOWN: {
            break;
        }
    }
}

void Paddle::handleRender(SDL_Renderer& renderer) {
    SDL_RenderFillRect(&renderer, rectangle->getRectangle());
}
