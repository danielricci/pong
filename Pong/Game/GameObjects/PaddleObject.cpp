#include "Game/GameObjects/PaddleObject.hpp"

#include <Eigen/Dense>

PaddleObject::PaddleObject(int x, int y, SDL_Keycode moveUp, SDL_Keycode moveDown) :
GameObject(x, y) {

    this->getTransform()->velocity() = Eigen::Vector2f(0, 5);
    
    paddleInputComponent->addBindings(moveUp, paddleInputComponent->ACTION_MOVE_UP);
    paddleInputComponent->addBindings(moveDown, paddleInputComponent->ACTION_MOVE_DOWN);
    addComponent(paddleInputComponent);
    
    renderComponent = new RenderComponent(WIDTH, HEIGHT);
    addComponent(renderComponent);
}
