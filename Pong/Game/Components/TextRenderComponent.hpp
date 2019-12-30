#pragma once

#include "Game/Components/RenderComponent.hpp"

#include <SDL.h>

class TextRenderComponent : RenderComponent {
public:
    TextRenderComponent(SDL_Renderer& renderer);
    ~TextRenderComponent();
    
    void setTexture(SDL_Surface& surface);
private:
    SDL_Texture* texture { nullptr };
    SDL_Renderer& renderer;
};
