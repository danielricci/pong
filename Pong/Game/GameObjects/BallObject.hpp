#pragma once

#include "Game/Components/CollisionComponent.hpp"
#include "Game/Components/RenderComponent.hpp"
#include "Game/GameObjects/GameObject.hpp"
#include "Game/Components/SoundComponent.hpp"

class BallObject : public GameObject {

public:
    inline static const int WIDTH { 10 };
    inline static const int HEIGHT { 10 };
    inline static const float INITIAL_VELOCITY_X { 7 };
    inline static const float INITIAL_VELOCITY_Y { 0 };
    
    BallObject(int x, int y);
    
    void playPaddleHitSound() const;
    void playScoreSound() const;
    void playWallHitSound() const;
    
private:
    CollisionComponent* collisionComponent = new CollisionComponent();
    RenderComponent* renderComponent = new RenderComponent();
    
    SoundComponent* paddleHitSound { nullptr };
    SoundComponent* scoreSound { nullptr };
    SoundComponent* wallHitSound { nullptr };
};
