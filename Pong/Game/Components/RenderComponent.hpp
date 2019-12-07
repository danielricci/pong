#pragma once

#include "Game/Components/Component.hpp"

#include <SDL.h>

class RenderComponent : public Component {
public:
    RenderComponent(int width, int height);
    
    virtual Type identifier() const override {
        return Component::Type::RenderComponent;
    }
    
    SDL_Rect rectangle() const {
        return rect;
    }
    
private:
    SDL_Rect rect;
};
