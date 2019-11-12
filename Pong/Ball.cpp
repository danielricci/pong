#include "Ball.hpp"

Ball::Ball(int x, int y) {
    rectangle = new Rectangle(x, y, WIDTH, HEIGHT);
}

void Ball::update() {
}

void Ball::render(SDL_Renderer& renderer) {
    SDL_RenderFillRect(&renderer, rectangle->getRectangle());
}
