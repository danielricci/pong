#pragma once

#include "Game/Components/Component.hpp"

#include <SDL.h>

class CollisionComponent : public Component {
public:
    bool isCollidedAABB(const SDL_Rect& r1, const SDL_Rect& r2) const {
        if(r1.x - (r2.x + r2.w) > 0 || r2.x - (r1.x + r1.w) > 0) {
            return false;
        }
        
        if(r1.y - (r2.y + r2.h) > 0 || r2.y - (r1.y + r1.h) > 0) {
            return false;
        }
        
        return true;
    }
};
