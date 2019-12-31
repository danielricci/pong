#pragma once

#include "Game/Components/Component.hpp"

#include <Eigen/Dense>
#include <SDL.h>

class TransformComponent : public Component {
public:
    TransformComponent() = default;

    TransformComponent(int x, int y, int width, int height) {
        this->position(0) = x;
        this->position(1) = y;
        this->dimension(0) = width;
        this->dimension(1) = height;
    }
        
    void applyVelocity() {
        this->position += velocity;
    }
    void undoVelocity() {
        this->position -= velocity;
    }
    
    void invertVelocityX() {
        this->velocity.x() *= -1;
    }
    
    void invertVelocityY() {
        this->velocity.y() *= -1;
    }
        
    SDL_Rect rectangle() const {
        SDL_Rect rectangle;
        rectangle.x = position(0);
        rectangle.y = position(1);
        rectangle.w = dimension(0);
        rectangle.h = dimension(1);
        
        return rectangle;
    }
    
    Eigen::Vector2f position { 0, 0 };
    Eigen::Vector2f velocity { 0, 0 };
    Eigen::Vector2f dimension { 0, 0 };
};
