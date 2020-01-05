#pragma once

#include "Game/GameObjects/BallObject.hpp"
#include "Game/GameObjects/ScoreObject.hpp"

#include <SDL.h>

#include <list>

class ScoringSystem {
public:
    ScoringSystem(SDL_Window& window);
    void process(BallObject* ballObject, const std::list<ScoreObject*>& scoreObjects);
private:
    int worldWidth;
    int worldHeight;
};
