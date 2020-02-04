#include "Game/GameObjects/BallObject.hpp"

#include <Eigen/Dense>

BallObject::BallObject(int x, int y) : GameObject(x, y, WIDTH, HEIGHT) {
    getTransform()->velocityVector = Eigen::Vector2f(INITIAL_VELOCITY_X, INITIAL_VELOCITY_Y);
    
    addComponent(collisionComponent);
    addComponent(renderComponent);
    
    paddleHitSound = new SoundComponent("Resources/Sounds/hit.wav");
    addComponent(paddleHitSound);
    
    scoreSound = new SoundComponent("Resources/Sounds/score.wav");
    addComponent(scoreSound);
    
    wallHitSound = new SoundComponent("Resources/Sounds/wall.wav");
    addComponent(wallHitSound);
}

void BallObject::playPaddleHitSound() const {
    paddleHitSound->play();
}

void BallObject::playScoreSound() const {
    scoreSound->play();
}

void BallObject::playWallHitSound() const {
    wallHitSound->play();
}
