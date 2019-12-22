#include "Game/GameObjects/BallObject.hpp"

#include <Eigen/Dense>

BallObject::BallObject(int x, int y) : GameObject(x, y, WIDTH, HEIGHT) {
    getTransform()->velocity = Eigen::Vector2f(5, 0);
    addComponent(collisionComponent);
    addComponent(renderComponent);
}
