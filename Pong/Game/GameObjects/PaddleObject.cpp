#include "Game/GameObjects/PaddleObject.hpp"

#include <Eigen/Dense>

PaddleObject::PaddleObject(int x, int y, SDL_Keycode moveUp, SDL_Keycode moveDown) :
GameObject(x, y, WIDTH, HEIGHT) {

    getTransform()->velocity = Eigen::Vector2f(0, 5);
    
    paddleInputComponent->addBindings(moveUp, paddleInputComponent->ACTION_MOVE_UP);
    paddleInputComponent->addBindings(moveDown, paddleInputComponent->ACTION_MOVE_DOWN);
    addComponent(paddleInputComponent);
    addComponent(renderComponent);
    addComponent(collisionComponent);
}
