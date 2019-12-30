#pragma once

#include "Game/Components/RenderComponent.hpp"

#include <SDL.h>

class TextRenderComponent : public RenderComponent {
public:
    TextRenderComponent(SDL_Renderer& renderer);
    ~TextRenderComponent();
    
    void setTexture(SDL_Surface& surface);
    SDL_Texture* getTexture() const { return texture; }
private:
    SDL_Texture* texture { nullptr };
    SDL_Renderer& renderer;
};
