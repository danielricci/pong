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
