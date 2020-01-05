#pragma once

#include "Game/Components/RenderComponent.hpp"

#include <SDL.h>

class TextRenderComponent : public RenderComponent {
public:
    TextRenderComponent(SDL_Renderer& renderer);
    ~TextRenderComponent();
    
    SDL_Texture* getTexture() const { return texture; }
    void createTexture(SDL_Surface& surface);
    
private:
    SDL_Texture* texture { nullptr };
    SDL_Renderer& renderer;
};
