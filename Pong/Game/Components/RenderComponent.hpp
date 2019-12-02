#pragma once

#include "Game/Components/Component.hpp"

#include <SDL.h>

class RenderComponent : public Component {
public:
    RenderComponent(int width, int height);
    
    virtual Type getIdentifier() const override {
        return Component::Type::RenderComponent;
    }
    
    SDL_Rect getRectangle() const {
        return rectangle;
    }
    
private:
    SDL_Rect rectangle;
};
