#pragma once

#include "Game/Components/RenderComponent.hpp"
#include "Game/Components/TextComponent.hpp"
#include "Game/Components/TextRenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"
#include "Game/GameObjects/PaddleObject.hpp"

#include <SDL.h>

class ScoreObject : public GameObject {
public:
    ScoreObject(int x, int y, SDL_Renderer& renderer);
    void setPaddleObject(const PaddleObject& paddleObject);
private:
    TextComponent* textComponent = new TextComponent("0", 40);
    TextRenderComponent* textRenderComponent { nullptr };
    const PaddleObject* paddleObject { nullptr };
};
