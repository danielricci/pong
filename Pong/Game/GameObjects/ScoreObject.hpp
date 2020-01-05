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
    const PaddleObject* getPaddleObject() const { return paddleObject; }
    void setPaddleObject(const PaddleObject& paddleObject) { this->paddleObject = &paddleObject; }
    
    int getScore() const { return score; }
    void setScore(int score);
    
private:
    TextComponent* textComponent = new TextComponent(40);
    TextRenderComponent* textRenderComponent { nullptr };
    const PaddleObject* paddleObject { nullptr };
    
    int score { 0 };
};
