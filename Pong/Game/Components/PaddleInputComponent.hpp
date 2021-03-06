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

#include "Game/Components/InputComponent.hpp"

#include <SDL.h>

#include <string>

class PaddleInputComponent : public InputComponent {
public:
    PaddleInputComponent(SDL_Keycode keyUp, SDL_Keycode keyDown);
    PaddleInputComponent(SDL_Keycode keyUp, SDL_Keycode keyDown, SDL_GameControllerAxis axis);

    
    int getDirection() const {
        return direction;
    }

    const std::string ACTION_MOVE_UP = "MoveUp";
    const std::string ACTION_MOVE_DOWN = "MoveDown";
    const std::string ACTION_MOVE = "Move";
    
private:
    
    int direction { 0 };
    
    void onMoveUp(const SDL_Event& event);
    void onMoveDown(const SDL_Event& event);
    void onMove(const SDL_Event& event);
};
