#pragma once

#include "Game/Components/CollisionComponent.hpp"
#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/Components/RenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

#include <SDL.h>

class PaddleObject : public GameObject {

public:
    inline static const int WIDTH { 6 };
    inline static const int HEIGHT { 70 };

    PaddleObject(int x, int y, SDL_Keycode moveUp, SDL_Keycode moveDown);
    ~PaddleObject() = default;
private:
    CollisionComponent* collisionComponent = new CollisionComponent();
    PaddleInputComponent* paddleInputComponent = new PaddleInputComponent();
    RenderComponent* renderComponent = new RenderComponent();
};
