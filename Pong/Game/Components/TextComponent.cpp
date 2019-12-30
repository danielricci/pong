#include "Game/Components/TextComponent.hpp"

#include <iostream>

TextComponent::TextComponent(std::string text, int size) {
    font = TTF_OpenFont(fontPath, size);
    if(font == nullptr) {
        std::cerr << "Could not open the specified font: " << text << std::endl;
    }
    else {
        setText(text);
    }
}

TextComponent::~TextComponent() {
    if(surface != nullptr) {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }
    if(font != nullptr) {
        TTF_CloseFont(font);
        font = nullptr;
    }
}

void TextComponent::setText(const std::string& text) {
    if(this->font == nullptr) {
        std::cerr << "Font is invalid, cannot set the specified text" << std::endl;
    }
    else if(this->text != text) {
        this->text = text;
        if(surface != nullptr) {
            SDL_FreeSurface(surface);
        }
        surface = TTF_RenderText_Blended(font, text.c_str(), color);
    }
}
