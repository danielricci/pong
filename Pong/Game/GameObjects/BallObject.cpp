#include "Game/GameObjects/BallObject.hpp"

#include <Eigen/Dense>

BallObject::BallObject(float x, float y) : GameObject(x, y) {
    //this->getTransform()->velocity() = Eigen::Vector2f(0, 1);
    this->addComponent(renderComponent);
}
