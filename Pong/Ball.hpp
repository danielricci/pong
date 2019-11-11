#pragma once

#include <SDL.h>
#include "Circle.hpp"

class Ball {
public:
    Ball(int x, int y);
    void update();
    void render(SDL_Renderer& renderer);
private:
    const int RADIUS { 7 };
    const int VELOCITY { 5 };
    Circle* circle { nullptr };
};
