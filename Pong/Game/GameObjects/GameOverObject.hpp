#pragma once

#include "Game/GameObjects/GameObject.hpp"
#include "Game/Components/TextComponent.hpp"
#include "Game/Components/TextRenderComponent.hpp"

#include <SDL.h>

#include <string>

class GameOverObject : public GameObject {
public:
    GameOverObject(int windowWidth, int windowHeight, SDL_Renderer& renderer);
    
    bool getIsGameOver() const { return isGameOver; }
    void setIsGameOver(bool isGameOver);
    
private:
    TextComponent* textComponent = new TextComponent(40);
    TextRenderComponent* textRenderComponent { nullptr };
    
    bool isGameOver { false };
    
    std::string GAME_OVER { "GAME OVER" };
};
