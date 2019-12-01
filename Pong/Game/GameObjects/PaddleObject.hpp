#pragma once

#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"

#include <SDL.h>

class PaddleObject : public GameObject {

public:
    PaddleObject(int x, int y, SDL_Keycode moveUp, SDL_Keycode moveDown);
    
private:
    PaddleInputComponent* paddleInputComponent = new PaddleInputComponent();
};
