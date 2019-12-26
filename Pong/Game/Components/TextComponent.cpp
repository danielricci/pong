#include "Game/Components/TextComponent.hpp"

#include <iostream>

TextComponent::TextComponent(const std::string& text, int size) {
    font = TTF_OpenFont(fontPath, size);
    if(font == nullptr) {
        std::cerr << "Could not open the specified font: " << text << std::endl;
    }
}

TextComponent::~TextComponent() {
    TTF_CloseFont(font);
}
