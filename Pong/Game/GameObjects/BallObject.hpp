#pragma once

#include "Game/Components/RenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

class BallObject : public GameObject {

public:
    BallObject(float x, float y);
    
private:
    const int WIDTH { 10 };
    const int HEIGHT { 10 };

    RenderComponent* renderComponent = new RenderComponent(WIDTH, HEIGHT);
};
