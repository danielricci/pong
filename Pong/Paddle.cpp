#include "Paddle.hpp"
#include <iostream>

Paddle::Paddle() {
    rectangle = new Rectangle(0, 0, 32, 32);
}

Paddle::~Paddle() {
    delete rectangle;
}

void Paddle::processInput(const SDL_Event& event) {
    if(event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch(event.key.keysym.sym) {
            case SDLK_UP:
                std::cout << "Up Pressed" << std::endl;
                break;
            case SDLK_DOWN:
                std::cout << "Down Pressed" << std::endl;
                break;
            default:
                return;
        }
    }
}

void Paddle::update(float deltaTime) {
    float result = rectangle->getX() + (velocity * deltaTime);
    rectangle->setX(result);
}

void Paddle::render(SDL_Renderer* renderer) {
    SDL_RenderFillRectF(renderer, rectangle->getRectangle())
}
