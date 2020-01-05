#include "Game/Components/CollisionComponent.hpp"
#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/Components/TransformComponent.hpp"
#include "Game/GameObjects/BallObject.hpp"
#include "Game/Systems/MovementSystem.hpp"

#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <SDL.h>

MovementSystem::MovementSystem(SDL_Window& window) {
    SDL_GetWindowSize(&window, &worldWidth, &worldHeight);
}

void MovementSystem::process(GameObject& currentGameObject, const std::list<GameObject*>& gameObjects) {
    PaddleInputComponent* paddleInputComponent = currentGameObject.getComponent<PaddleInputComponent>();
    if(paddleInputComponent != nullptr) {
        // FIXME: Can't we simply just get the transform component and apply it to the direction AT THE SOURCE?
        int direction = paddleInputComponent->getDirection();
        if(direction != 0) {
            TransformComponent* transform = currentGameObject.getTransform();
            Eigen::Vector2f velocity = transform->velocity;
            velocity.y() = std::abs(velocity.y()) * direction;
            
            int newPosition = velocity.y() + transform->position.y();
            if(newPosition >= 0 && newPosition + transform->dimension.y() <= worldHeight) {
                transform->velocity = velocity;
                transform->applyVelocity();
            }
        }
    }
    else {
        BallObject* ball = dynamic_cast<BallObject*>(&currentGameObject);
        if(ball != nullptr) {
            TransformComponent* transformComponent = ball->getTransform();
            if(transformComponent->position.y() <= 0 || transformComponent->position.y() + transformComponent->dimension.y() >= worldHeight) {
                transformComponent->invertVelocityY();
                transformComponent->applyVelocity();
            }
            else if(transformComponent->position.x() <= 0 || transformComponent->position.x() + transformComponent->dimension.x() >= worldWidth) {
                // Position the ball at the center of the arena
                // The direction of the ball should point towards the player that lost the point
                transformComponent->position.x() = worldWidth/2 - (transformComponent->dimension.x() / 2);
                transformComponent->position.y() = worldHeight/2 - (transformComponent->dimension.y() / 2);
                transformComponent->velocity.x() = BallObject::INITIAL_VELOCITY_X * (transformComponent->velocity.x() < 0 ? -1 : 1);
                transformComponent->velocity.y() = BallObject::INITIAL_VELOCITY_Y;
            }
            else {
                transformComponent->applyVelocity();
                SDL_Rect ballRect = ball->getTransform()->rectangle();
                for(GameObject* gameObject : gameObjects) {
                    if(gameObject != ball && gameObject->getComponent<CollisionComponent>() != nullptr) {
                        SDL_Rect gameObjectRect = gameObject->getTransform()->rectangle();
                        if(SDL_HasIntersection(&ballRect, &gameObjectRect)) {
                            transformComponent->undoVelocity();
                            transformComponent->invertVelocityX();
                            
                            int sectorSize = gameObjectRect.h / paddleSectors;
                            int hitPosition = std::abs((transformComponent->position.y() + (transformComponent->dimension.y() / 2)) - gameObjectRect.y) / sectorSize;
                            std::cout << hitPosition << std::endl;
                            switch(hitPosition + 1) {
                                case 1:
                                    transformComponent->velocity.y() = -4;
                                case 2:
                                    transformComponent->velocity.y() = -2;
                                    break;
                                case 3:
                                    transformComponent->velocity.y() = 0;
                                    break;
                                case 4:
                                    transformComponent->velocity.y() = 2;
                                    break;
                                case 5:
                                    transformComponent->velocity.y() = 4;
                                    break;
                            }
                            transformComponent->applyVelocity();
                            break;
                        }
                    }
                }
            }
        }
    }
}
