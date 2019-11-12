#pragma once

#include <SDL.h>
#include "Rectangle.hpp"

class Ball {
public:
    Ball(int x, int y);
    void update();
    void render(SDL_Renderer& renderer);
private:
    const int WIDTH { 7 };
    const int HEIGHT { WIDTH };
    const int VELOCITY { 5 };
    Rectangle* rectangle { nullptr };
};
