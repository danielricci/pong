#pragma once

#include "Game/Components/InputComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"
#include "Game/Primitives/Rectangle.hpp"

class Paddle : public GameObject {

public:
    // TODO Remove upBinding and downBinding, this should be put within the PaddleInputBinding constructor or in its parent
    Paddle(int x, int y, SDL_Keycode upBinding, SDL_Keycode downBinding);
    ~Paddle();
        
    // TODO - remove me
    static void setMaximalHeight(int maximalHeight) {
        Paddle::maximalHeight = maximalHeight;
    }
    
    virtual void render(SDL_Renderer& renderer) override;
    virtual void update(const SDL_Event& event) override;
    
private:
    
    const int WIDTH { 5 };
    const int HEIGHT { 75 };
    const int VELOCITY { 5 };
        
    Rectangle* rectangle { nullptr };
    
    static int maximalHeight;

    InputComponent* inputComponent { nullptr };
};
