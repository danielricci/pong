/**
* MIT License
*
* Copyright (c) 2020 Daniel Ricci {@literal <thedanny09@icloud.com>}
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "Game/Components/CollisionComponent.hpp"
#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/Components/SoundComponent.hpp"
#include "Game/Components/TransformComponent.hpp"
#include "Game/Systems/MovementSystem.hpp"

#include <Eigen/Dense>
#include <SDL.h>

#include <cmath>
#include <iostream>

MovementSystem::MovementSystem(SDL_Window& window) {
    SDL_GetWindowSize(&window, &worldWidth, &worldHeight);
}

void MovementSystem::process(const std::list<GameObject*>& gameObjects) {
    this->gameObjects = gameObjects;
    for(GameObject* gameObject : gameObjects) {
        if(gameObject != nullptr) {
            PaddleObject* paddleObject = dynamic_cast<PaddleObject*>(gameObject);
            if(paddleObject != nullptr) {
                processPaddleMovement(paddleObject);
            }
            else {
                BallObject* ballObject = dynamic_cast<BallObject*>(gameObject);
                if(ballObject) {
                    processBallMovement(ballObject);
                }
           }
        }
    }
    this->gameObjects.empty();
}

void MovementSystem::processBallMovement(BallObject* ballObject) const {
    if(ballObject != nullptr) {
        TransformComponent* ballTransformComponent = ballObject->getTransform();
        if(ballTransformComponent->positionVector.y() <= 0 || ballTransformComponent->positionVector.y() + ballTransformComponent->dimensionVector.y() >= worldHeight) {
            ballTransformComponent->invertVelocityY();
            ballTransformComponent->applyVelocity();
            
            // Play the sound for hitting a wall
            ballObject->playWallHitSound();
        }
        else if(ballTransformComponent->positionVector.x() <= 0 || ballTransformComponent->positionVector.x() + ballTransformComponent->dimensionVector.x() >= worldWidth) {
            // Position the ball at the center of the arena
            // The direction of the ball should point towards the player that lost the point
            ballTransformComponent->positionVector.x() = worldWidth/2 - (ballTransformComponent->dimensionVector.x() / 2);
            ballTransformComponent->positionVector.y() = worldHeight/2 - (ballTransformComponent->dimensionVector.y() / 2);
            ballTransformComponent->velocityVector.x() = BallObject::INITIAL_VELOCITY_X * (ballTransformComponent->velocityVector.x() < 0 ? -1 : 1);
            ballTransformComponent->velocityVector.y() = BallObject::INITIAL_VELOCITY_Y;
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
                        int hitPosition = std::abs((ballTransformComponent->positionVector.y() + (ballTransformComponent->dimensionVector.y() / 2)) - gameObjectRect.y) / sectionSize;
                        
                        // Note: Only an upper-limit is required. If the absolute value is no longer used to determine the hit position
                        //       then a proper lower-limit is required.
                        hitPosition = std::min(hitPosition, PADDLE_SECTIONS - 1);
                        
                        switch(hitPosition) {
                            case 0:
                                ballTransformComponent->velocityVector.y() = -5;
                                break;
                            case 1:
                                ballTransformComponent->velocityVector.y() = -2;
                                break;
                            case 2:
                                ballTransformComponent->velocityVector.y() = 0;
                                break;
                            case 3:
                                ballTransformComponent->velocityVector.y() = 2;
                                break;
                            case 4:
                                ballTransformComponent->velocityVector.y() = 5;
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

void MovementSystem::processPaddleMovement(PaddleObject* paddleObject) const {
    
    // Calculate the direction that the paddle should go in
    int direction = 0;
    PaddleInputComponent* paddleInputComponent = paddleObject->getComponent<PaddleInputComponent>();
    if(paddleInputComponent != nullptr && paddleInputComponent->enabled) {
        direction = paddleInputComponent->getDirection();
    }
    else {
        for(GameObject* gameObject : this->gameObjects) {
            if(dynamic_cast<BallObject*>(gameObject) != nullptr) {
                int ballPositionY = gameObject->getTransform()->positionVector.y() + (gameObject->getTransform()->dimensionVector.y() / 2);
                int paddlePositionY = paddleObject->getTransform()->positionVector.y() + (paddleObject->getTransform()->dimensionVector.y() / 2);
                if(ballPositionY < paddlePositionY) {
                    direction = -1;
                }
                else if(ballPositionY > paddlePositionY) {
                    direction = 1;
                }
                                
                break;
            }
        }
    }

    // Apply the paddle movement
    if(direction != 0) {
        TransformComponent* transform = paddleObject->getTransform();
        Eigen::Vector2f velocity = transform->velocityVector;
        velocity.y() = std::abs(velocity.y()) * direction;
        
        int newPosition = velocity.y() + transform->positionVector.y();
        if(newPosition >= 0 && newPosition + transform->dimensionVector.y() <= worldHeight) {
            transform->velocityVector = velocity;
            transform->applyVelocity();
        }
    }
}
