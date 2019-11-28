#pragma once

#include "Game/GameObjects/GameObject.hpp"

#include <SDL.h>

class PaddleObject : public GameObject {

public:
    PaddleObject(int x, int y);
    void foo(SDL_Event event);
};
