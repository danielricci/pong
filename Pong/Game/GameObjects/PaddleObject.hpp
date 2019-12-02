#pragma once

#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/Components/RenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

#include <SDL.h>

class PaddleObject : public GameObject {

public:
    PaddleObject(int x, int y, SDL_Keycode moveUp, SDL_Keycode moveDown);
    ~PaddleObject() = default;
    
private:
    
    const int WIDTH { 5 };
    const int HEIGHT { 75 };
    
    PaddleInputComponent* paddleInputComponent = new PaddleInputComponent();
    RenderComponent* renderComponent { nullptr };
};
