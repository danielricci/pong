#pragma once

#include "Game/GameObjects/GameObject.hpp"
#include "Game/Primitives/Rectangle.hpp"

#include <SDL.h>

class Ball /*: public GameObject */{
public:
    Ball(int x, int y);
    void update();
    void render(SDL_Renderer& renderer);
private:
    const int WIDTH { 7 };
    const int HEIGHT { WIDTH };
    const int VELOCITY { 1 };
    Rectangle* rectangle { nullptr };
};
