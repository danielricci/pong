#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/Components/TransformComponent.hpp"
#include "Game/GameObjects/BallObject.hpp"
#include "Game/Systems/MovementSystem.hpp"

#include <Eigen/Dense>
#include <cmath>

void MovementSystem::process(GameObject& currentGameObject, const std::list<GameObject*>& gameObjects) const {
    PaddleInputComponent* paddleInputComponent = currentGameObject.getComponent<PaddleInputComponent>();
    if(paddleInputComponent != nullptr) {
        // TODO: Can't we simply just get the transform component and apply it to the direction AT THE SOURCE?
        int direction = paddleInputComponent->getDirection();
        if(direction != 0) {
            TransformComponent* transform = currentGameObject.getTransform();
            Eigen::Vector2f velocity = transform->velocity;
            velocity.y() = std::abs(velocity.y()) * direction;
            if(velocity.y() + transform->position.y() >= 0) {
                transform->velocity = velocity;
                transform->applyVelocity();
            }
        }
    }
    else {
        BallObject* ball = dynamic_cast<BallObject*>(&currentGameObject);
        if(ball != nullptr) {
            TransformComponent* transformComponent = currentGameObject.getTransform();
            transformComponent->applyVelocity();
            SDL_Rect ballRect = ball->getTransform()->rectangle();
            for(GameObject* gameObject : gameObjects) {
                if(gameObject != ball) {
                    SDL_Rect gameObjectRect = gameObject->getTransform()->rectangle();
                    if(SDL_HasIntersection(&ballRect, &gameObjectRect)) {
                        // TODO: Can we hug the object instead?
                        transformComponent->undoVelocity();
                        transformComponent->invertVelocityX();
                        transformComponent->applyVelocity();
                        break;
                    }
                }
            }
        }
    }
}
