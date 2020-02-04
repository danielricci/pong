#include "Game/Systems/ScoringSystem.hpp"
#include "Game/Components/TextComponent.hpp"
#include "Game/Components/TransformComponent.hpp"

#include <cmath>
#include <iostream>

ScoringSystem::ScoringSystem(SDL_Window& window) {
    SDL_GetWindowSize(&window, &worldWidth, &worldHeight);
}

void ScoringSystem::process(BallObject* ballObject, const std::list<ScoreObject*>& scoreObjects) {
    if(ballObject != nullptr) {
        TransformComponent* ballTransformComponent { ballObject->getTransform() };
        if(ballTransformComponent->positionVector.x() <= 0 || ballTransformComponent->positionVector.x() + ballTransformComponent->dimensionVector.x() >= worldWidth) {
            ScoreObject* farthestScoreObject { nullptr };
            for(ScoreObject* scoreObject : scoreObjects) {
                if(farthestScoreObject == nullptr || std::abs(scoreObject->getPaddleObject()->getTransform()->positionVector.x() - ballTransformComponent->positionVector.x()) > std::abs(farthestScoreObject->getPaddleObject()->getTransform()->positionVector.x() - ballTransformComponent->positionVector.x())) {
                    farthestScoreObject = scoreObject;
                }
            }
            if(farthestScoreObject != nullptr) {
                farthestScoreObject->setScore(farthestScoreObject->getScore() + 1);
                ballObject->playScoreSound();
            }
        }
    }
}
