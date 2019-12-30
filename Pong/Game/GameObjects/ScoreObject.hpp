#pragma once

#include "Game/Components/RenderComponent.hpp"
#include "Game/Components/TextComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

class ScoreObject : public GameObject {
public:
    ScoreObject(int x, int y);
private:
    RenderComponent* renderComponent = new RenderComponent();
    TextComponent* textComponent = new TextComponent("0", 40);
};
