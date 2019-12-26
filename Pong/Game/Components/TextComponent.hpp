#pragma once

#include "Game/Components/Component.hpp"

#include <SDL_ttf.h>

#include <string>

class TextComponent : public Component {
public:
    TextComponent(const std::string& text, int size);
    ~TextComponent();
private:
    TTF_Font* font { nullptr };
    const char* fontPath = "Resources/Fonts/Verdana.ttf";
};
