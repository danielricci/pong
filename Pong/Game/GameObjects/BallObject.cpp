#include "Game/GameObjects/BallObject.hpp"

#include <Eigen/Dense>

BallObject::BallObject(int x, int y) : GameObject(x, y, WIDTH, HEIGHT) {
    getTransform()->velocity = Eigen::Vector2f(INITIAL_VELOCITY_X, INITIAL_VELOCITY_Y);
    addComponent(collisionComponent);
    addComponent(renderComponent);
}
