#pragma once

#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/Components/RenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

#include <SDL.h>

class PaddleObject : public GameObject {

public:
    PaddleObject(int x, int y, SDL_Keycode moveUp, SDL_Keycode moveDown);
    ~PaddleObject() = default;
    
    inline static const int WIDTH { 6 };
    inline static const int HEIGHT { 70 };
    
private:
    PaddleInputComponent* paddleInputComponent = new PaddleInputComponent();
    RenderComponent* renderComponent { nullptr };
};
