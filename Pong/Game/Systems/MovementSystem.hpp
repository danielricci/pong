#pragma once

#include "Game/GameObjects/GameObject.hpp"

class MovementSystem {
public:
    void process(GameObject* gameObject) const;
};
