#pragma once

#include "Game/GameObjects/GameObject.hpp"

#include <SDL.h>

class RenderSystem {
    
public:
    RenderSystem(SDL_Renderer& renderer);
    void update(GameObject* gameObject);
private:
    
    SDL_Rect mergeRectangles(const SDL_Rect& r1, const SDL_Rect& r2) const;
    
    SDL_Renderer& renderer;
};
