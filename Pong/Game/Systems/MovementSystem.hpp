#pragma once

#include "Game/GameObjects/GameObject.hpp"

#include <list>

class MovementSystem {
public:
    void process(GameObject& currentGameObject, const std::list<GameObject*>& gameObjects) const;
};
