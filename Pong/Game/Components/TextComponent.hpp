#pragma once

#include "Game/Components/Component.hpp"

#include <SDL_ttf.h>

#include <string>

class TextComponent : public Component {
public:
    TextComponent(std::string text, int size);
    ~TextComponent();
    
    void setText(const std::string& text);
private:    
    TTF_Font* font { nullptr };
    
    // TODO: Should the surface be put within the TextRenderComponent instead?
    SDL_Surface* surface { nullptr };
    SDL_Color color { 255, 255, 255 };
    
    const char* fontPath = "Resources/Fonts/Verdana.ttf";
    std::string text;
};
