#include "Game/GameObjects/PaddleObject.hpp"

PaddleObject::PaddleObject(int x, int y, SDL_Keycode moveUp, SDL_Keycode moveDown) :
GameObject(x, y) {
    
    getTransform()->setVelocity(5);
    
    paddleInputComponent->addBindings(moveUp, paddleInputComponent->ACTION_MOVE_UP);
    paddleInputComponent->addBindings(moveDown, paddleInputComponent->ACTION_MOVE_DOWN);
    addComponent(paddleInputComponent);
    
    renderComponent = new RenderComponent(WIDTH, HEIGHT);
    addComponent(renderComponent);
}
