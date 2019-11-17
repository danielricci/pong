#pragma once

#include <SDL.h>

class GameObject {
public:
    virtual void input(const SDL_Event& event) = 0;
    virtual void render(SDL_Renderer& renderer) = 0;
    virtual void update() = 0;
private:
};
