#include "Game/GameObjects/BallObject.hpp"

BallObject::BallObject(int x, int y) : GameObject(x, y) {
    getTransform()->setVelocity(VELOCITY);
    addComponent(renderComponent);
}
