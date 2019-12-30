#include "Game/Components/TextRenderComponent.hpp"

#include <iostream>

TextRenderComponent::TextRenderComponent(SDL_Renderer& renderer) : renderer(renderer) {
}

TextRenderComponent::~TextRenderComponent() {
    if(texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

void TextRenderComponent::setTexture(SDL_Surface& surface) {
    if(texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    
    texture = SDL_CreateTextureFromSurface(&renderer, &surface);
    if(texture == nullptr) {
        std::cerr << "Could not create the texture from the specified surface" << std::endl;
    }
}
