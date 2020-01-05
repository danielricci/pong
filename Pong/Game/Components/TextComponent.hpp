#pragma once

#include "Game/Components/Component.hpp"

#include <SDL_ttf.h>

#include <string>

class TextComponent : public Component {
public:
    TextComponent(int size);
    ~TextComponent();
    
    std::string getText() const { return text; }
    void setText(const std::string& text);
    
    SDL_Surface* getSurface() const { return surface; }
private:    
    void createSurface();
    
    TTF_Font* font { nullptr };
    
    SDL_Surface* surface { nullptr };
    SDL_Color color { 255, 255, 255 };
    
    const char* fontPath = "Resources/Fonts/Verdana.ttf";
    std::string text;
};
