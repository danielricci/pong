#include "Game/GameObjects/PaddleObject.hpp"

#include <Eigen/Dense>

PaddleObject::PaddleObject(int x, int y) : GameObject(x, y, WIDTH, HEIGHT) {
    getTransform()->velocityVector = Eigen::Vector2f(0, 5);
    
    addComponent(renderComponent);
    addComponent(collisionComponent);
}
