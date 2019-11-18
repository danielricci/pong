#include "Paddle.hpp"


int Paddle::maximalHeight { 0 };

Paddle::Paddle(int x, int y, SDL_Keycode upBinding, SDL_Keycode downBinding) {
    rectangle = new Rectangle(x, y, WIDTH, HEIGHT);
    paddleInputComponent = new PaddleInputComponent(*this, upBinding, downBinding);
}

Paddle::~Paddle() {
    delete rectangle;
}


void Paddle::update(const SDL_Event& event) {
    paddleInputComponent->update(event);
//    if(this->direction != Direction::NONE) {
//        int newPosition = rectangle->getRectangle()->y + (VELOCITY * static_cast<int>(this->direction));
//        if(newPosition >= 0 && newPosition <= (maximalHeight - HEIGHT)) {
//            rectangle->getRectangle()->y = newPosition;
//        }
//    }
}

void Paddle::render(SDL_Renderer& renderer) {
    SDL_RenderFillRect(&renderer, rectangle->getRectangle());
}
