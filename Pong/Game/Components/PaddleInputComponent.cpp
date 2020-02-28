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

#include "PaddleInputComponent.hpp"

#include <iostream>

PaddleInputComponent::PaddleInputComponent(SDL_Keycode keyUp, SDL_Keycode keyDown) {
    this->addBindings(keyUp, ACTION_MOVE_UP);
    this->addBindings(keyDown, ACTION_MOVE_DOWN);

    registerActionBinding(ACTION_MOVE_UP, std::bind(&PaddleInputComponent::onMoveUp, this, std::placeholders::_1));
    registerActionBinding(ACTION_MOVE_DOWN, std::bind(&PaddleInputComponent::onMoveDown, this, std::placeholders::_1));
}

PaddleInputComponent::PaddleInputComponent(SDL_Keycode keyUp, SDL_Keycode keyDown, SDL_GameControllerAxis axis) : PaddleInputComponent(keyUp, keyDown) {
    this->addBindings(axis, ACTION_MOVE);
    registerActionBinding(ACTION_MOVE, std::bind(&PaddleInputComponent::onMove, this, std::placeholders::_1));
}

void PaddleInputComponent::onMoveUp(const SDL_Event& event) {
    switch(event.type) {
        case SDL_KEYDOWN: {
            direction = -1;
            break;
        }
        case SDL_KEYUP: {
            if(direction == -1) {
                direction = 0;
            }
            break;
        }
    }
}

void PaddleInputComponent::onMoveDown(const SDL_Event& event) {
    switch(event.type) {
        case SDL_KEYDOWN: {
            direction = 1;
            break;
        }
        case SDL_KEYUP: {
            if(direction == 1) {
                direction = 0;
            }
            break;
        }
    }
}


void PaddleInputComponent::onMove(const SDL_Event& event) {
    if(event.type == SDL_CONTROLLERAXISMOTION) {
        if(event.caxis.value < -getDeadZone()) {
            direction = -1;
        }
        else if(event.caxis.value > getDeadZone()) {
            direction = 1;
        }
        else {
            direction = 0;
        }
    }
}
