#pragma once

#include "Game/Components/RenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

class BallObject : public GameObject {

public:
    BallObject(float x, float y);
    
private:
    const int WIDTH { 5 };
    const int HEIGHT { 5 };

    RenderComponent* renderComponent = new RenderComponent(WIDTH, HEIGHT);
};
