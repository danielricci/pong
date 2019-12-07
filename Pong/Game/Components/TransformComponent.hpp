#pragma once

#include "Game/Components/Component.hpp"

#include <Eigen/Dense>
#include <SDL.h>

class TransformComponent : public Component {
public:
    TransformComponent() = default;

    TransformComponent(int x, int y) {
        this->positionVector(0) = x;
        this->positionVector(1) = y;
    }
    
    Eigen::Vector2f& position() {
        return positionVector;
    }
    
    Eigen::Vector2f& velocity() {
        return velocityVector;
    }
    
    void applyVelocity() {
        this->positionVector += velocityVector;
    }
    
    virtual Type identifier() const override {
        return Component::Type::TransformComponent;
    }
    
    SDL_Rect rectangle() const {
        SDL_Rect rectangle;
        rectangle.x = positionVector(0);
        rectangle.y = positionVector(1);
        rectangle.w = 0;
        rectangle.h = 0;
        
        return rectangle;
    }
    
private:
    Eigen::Vector2f positionVector { 0, 0 };
    Eigen::Vector2f velocityVector { 0, 0 };
};
