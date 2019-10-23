#include "Player.hpp"

Player::Player() {
    rectangle->x = 0;
    rectangle->y = 0;
    rectangle->w = 32;
    rectangle->h = 32;
}

Player::~Player() {
    delete rectangle;
}

void Player::input(const SDL_Event& event) {
    if(event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch(event.key.keysym.sym) {
            case SDLK_UP:
                break;
            case SDLK_DOWN:
                break;
            case SDLK_LEFT:
                break;
            case SDLK_RIGHT:
                break;
        }
    }
}

void Player::update(float deltaTime) {
}

void Player::render() {
}
