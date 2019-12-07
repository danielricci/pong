#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/Components/TransformComponent.hpp"
#include "Game/Systems/MovementSystem.hpp"

void MovementSystem::process(GameObject* gameObject) const {
    if(gameObject != nullptr) {
        PaddleInputComponent* paddleInputComponent = gameObject->getComponent<PaddleInputComponent>();
        if(paddleInputComponent != nullptr) {
            // Get the direction of the paddle
             int direction = paddleInputComponent->getDirection();
             if(direction != 0) {
                 // Move the transform of the paddle with the velocity in the direct specified
                 //TransformComponent* transform = gameObject->getTransform();
                 //transform->applyVelocity();
             }
        }
    }
}
