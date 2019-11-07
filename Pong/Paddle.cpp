#include "Paddle.hpp"

int Paddle::maximalHeight { 0 };

Paddle::Paddle(int x, int y) {
    rectangle = new Rectangle(x, y, WIDTH, HEIGHT);
}

Paddle::~Paddle() {
    delete rectangle;
}

void Paddle::input(const SDL_Event& event) {
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

void Paddle::update() {
    if(this->direction != Direction::NONE) {
        int newPosition = rectangle->getRectangle()->y + (VELOCITY * static_cast<int>(this->direction));
        if(newPosition >= 0 && newPosition <= (maximalHeight - HEIGHT)) {
            rectangle->getRectangle()->y = newPosition;
        }
    }
}

void Paddle::render(SDL_Renderer& renderer) {
    SDL_RenderFillRect(&renderer, rectangle->getRectangle());
}
