#pragma once

#include "Game/GameObjects/GameObject.hpp"

#include <SDL.h>

class RenderSystem {
    
public:
    RenderSystem(SDL_Renderer& renderer) : renderer(renderer){
    }
    void update(GameObject* gameObject);
private:
    SDL_Renderer& renderer;
};
