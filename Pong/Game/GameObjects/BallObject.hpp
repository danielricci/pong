#pragma once

#include "Game/Components/RenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

class BallObject : public GameObject {

public:
    BallObject(int x, int y);
    ~BallObject() = default;
    
private:
    
    const int VELOCITY { 1 };
    const int WIDTH { 5 };
    const int HEIGHT { WIDTH };

    RenderComponent* renderComponent = new RenderComponent(WIDTH, HEIGHT);
};
