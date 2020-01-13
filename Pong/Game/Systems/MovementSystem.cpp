#include "Game/Components/CollisionComponent.hpp"
#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/Components/SoundComponent.hpp"
#include "Game/Components/TransformComponent.hpp"
#include "Game/GameObjects/BallObject.hpp"
#include "Game/Systems/MovementSystem.hpp"

#include <Eigen/Dense>
#include <SDL.h>

#include <cmath>
#include <iostream>

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
        BallObject* ballObject = dynamic_cast<BallObject*>(&currentGameObject);
        if(ballObject != nullptr) {
            TransformComponent* ballTransformComponent = ballObject->getTransform();
            if(ballTransformComponent->position.y() <= 0 || ballTransformComponent->position.y() + ballTransformComponent->dimension.y() >= worldHeight) {
                ballTransformComponent->invertVelocityY();
                ballTransformComponent->applyVelocity();
                
                // Play the sound for hitting a wall
                ballObject->playWallHitSound();
            }
            else if(ballTransformComponent->position.x() <= 0 || ballTransformComponent->position.x() + ballTransformComponent->dimension.x() >= worldWidth) {
                // Position the ball at the center of the arena
                // The direction of the ball should point towards the player that lost the point
                ballTransformComponent->position.x() = worldWidth/2 - (ballTransformComponent->dimension.x() / 2);
                ballTransformComponent->position.y() = worldHeight/2 - (ballTransformComponent->dimension.y() / 2);
                ballTransformComponent->velocity.x() = BallObject::INITIAL_VELOCITY_X * (ballTransformComponent->velocity.x() < 0 ? -1 : 1);
                ballTransformComponent->velocity.y() = BallObject::INITIAL_VELOCITY_Y;
            }
            else {
                ballTransformComponent->applyVelocity();
                SDL_Rect ballRect = ballObject->getTransform()->rectangle();
                for(GameObject* gameObject : gameObjects) {
                    if(gameObject != ballObject && gameObject->getComponent<CollisionComponent>() != nullptr) {
                        SDL_Rect gameObjectRect = gameObject->getTransform()->rectangle();
                        if(gameObject->getComponent<CollisionComponent>()->isCollidedAABB(ballRect, gameObjectRect)) {
                            ballTransformComponent->undoVelocity();
                            ballTransformComponent->invertVelocityX();
                            
                            // Calculate the position of where the ball hit the paddle
                            int sectionSize = gameObjectRect.h / PADDLE_SECTIONS;
                            int hitPosition = std::abs((ballTransformComponent->position.y() + (ballTransformComponent->dimension.y() / 2)) - gameObjectRect.y) / sectionSize;
                            
                            // Note: Only an upper-limit is required. If the absolute value is no longer used to determine the hit position
                            //       then a proper lower-limit is required.
                            hitPosition = std::min(hitPosition, PADDLE_SECTIONS - 1);
                            
                            switch(hitPosition) {
                                case 0:
                                    ballTransformComponent->velocity.y() = -4;
                                case 1:
                                    ballTransformComponent->velocity.y() = -2;
                                    break;
                                case 2:
                                    ballTransformComponent->velocity.y() = 0;
                                    break;
                                case 3:
                                    ballTransformComponent->velocity.y() = 2;
                                    break;
                                case 4:
                                    ballTransformComponent->velocity.y() = 4;
                                    break;
                                default:
                                    std::cerr << "Could not calculate hit position for " << hitPosition << std::endl;
                                    break;
                            }
                            ballTransformComponent->applyVelocity();

                            // Play the sound for hitting a paddle
                            ballObject->playPaddleHitSound();
                            break;
                        }
                    }
                }
            }
        }
    }
}
