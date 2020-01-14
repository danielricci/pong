#pragma once

#include "Game/Components/CollisionComponent.hpp"
#include "Game/Components/RenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

class PaddleObject : public GameObject {
public:
    // TODO Get rid of this
    inline static const int WIDTH { 6 };
    inline static const int HEIGHT { 100 };

    PaddleObject(int x, int y);
    ~PaddleObject() = default;
private:
    CollisionComponent* collisionComponent = new CollisionComponent();
    RenderComponent* renderComponent = new RenderComponent();
};
