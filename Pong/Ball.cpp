#include "Ball.hpp"

#include <SDL2_gfxPrimitives.h>

Ball::Ball(int x, int y) {
    circle = new Circle(x, y, RADIUS);
}

void Ball::update() {
}

void Ball::render(SDL_Renderer& renderer) {
    filledCircleRGBA(&renderer, circle->h, circle->k, circle->radius, 0xFF, 0xFF, 0xFF, 255);
}
