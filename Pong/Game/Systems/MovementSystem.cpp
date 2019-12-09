#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/Components/TransformComponent.hpp"
#include "Game/Systems/MovementSystem.hpp"

#include <Eigen/Dense>
#include <cmath>


void MovementSystem::process(GameObject* gameObject) const {
    if(gameObject != nullptr) {
        PaddleInputComponent* paddleInputComponent = gameObject->getComponent<PaddleInputComponent>();
        if(paddleInputComponent != nullptr) {
            int direction = paddleInputComponent->getDirection();
            if(direction != 0) {
                TransformComponent* transform = gameObject->getTransform();
                Eigen::Vector2f velocity = transform->velocity();
                velocity.y() = std::abs(velocity.y()) * direction;
                transform->velocity() = velocity;
                transform->applyVelocity();
            }
        }
    }
}
