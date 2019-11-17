#include "Ball.hpp"

Ball::Ball(int x, int y) {
    rectangle = new Rectangle(x, y, WIDTH, HEIGHT);
}

//void GameObject::input(const SDL_Event& event) {
//}

void Ball::update() {
    rectangle->getRectangle()->x -= VELOCITY;
}

void Ball::render(SDL_Renderer& renderer) {
    SDL_RenderFillRect(&renderer, rectangle->getRectangle());
}
