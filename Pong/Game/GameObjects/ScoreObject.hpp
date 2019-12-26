#pragma once

#include "Game/Components/RenderComponent.hpp"
#include "Game/Components/TextComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

class ScoreObject : public GameObject {
public:
    ScoreObject(int x, int y);
private:
    inline static const int WIDTH { 20 };
    inline static const int HEIGHT { 20 };
    
    RenderComponent* renderComponent = new RenderComponent();
    TextComponent* textComponent = new TextComponent("Hello World", 12);
};
