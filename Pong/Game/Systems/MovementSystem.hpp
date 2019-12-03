#pragma once

#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

class MovementSystem {
public:
    void process(GameObject* gameObject) const;
};
