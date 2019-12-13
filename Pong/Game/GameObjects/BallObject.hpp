#pragma once

#include "Game/Components/RenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

class BallObject : public GameObject {

public:
    BallObject(float x, float y);

    inline static const int WIDTH { 10 };
    inline static const int HEIGHT { 10 };
private:
    
    RenderComponent* renderComponent = new RenderComponent(WIDTH, HEIGHT);
};
