#pragma once

#include "Game/Components/Component.hpp"

#include <Eigen/Dense>
#include <SDL.h>

class TransformComponent : public Component {
public:
    TransformComponent() = default;

    TransformComponent(int x, int y, int width, int height) {
        this->positionVector(0) = x;
        this->positionVector(1) = y;
        this->dimensionVector(0) = width;
        this->dimensionVector(1) = height;
    }
        
    void applyVelocity() {
        this->positionVector += velocityVector;
    }
    void undoVelocity() {
        this->positionVector -= velocityVector;
    }
    
    void invertVelocityX() {
        this->velocityVector.x() *= -1;
    }
    
    void invertVelocityY() {
        this->velocityVector.y() *= -1;
    }
        
    SDL_Rect rectangle() const {
        SDL_Rect rectangle;
        rectangle.x = positionVector(0);
        rectangle.y = positionVector(1);
        rectangle.w = dimensionVector(0);
        rectangle.h = dimensionVector(1);
        
        return rectangle;
    }
    
    Eigen::Vector2f positionVector { 0, 0 };
    Eigen::Vector2f velocityVector { 0, 0 };
    Eigen::Vector2f dimensionVector { 0, 0 };
};
