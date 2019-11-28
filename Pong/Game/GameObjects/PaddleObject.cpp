#include "Game/GameObjects/PaddleObject.hpp"
#include "Game/Components/PaddleInputComponent.hpp"

PaddleObject::PaddleObject(int x, int y) :
GameObject(x, y) {
    PaddleInputComponent* component = new PaddleInputComponent();
    component->addBindings(SDLK_a, component->ACTION_MOVE_UP);
    addComponent(component);
}

void PaddleObject::foo(SDL_Event event) {
    this->getComponent<PaddleInputComponent>()->handleEvent(event);
}
