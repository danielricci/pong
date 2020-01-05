#include "Game/GameObjects/ScoreObject.hpp"

ScoreObject::ScoreObject(int x, int y, SDL_Renderer& renderer) : GameObject(x, y) {
    textComponent->setText(std::to_string(score));
    addComponent(textComponent);
    textRenderComponent = new TextRenderComponent(renderer);
    addComponent(textRenderComponent);
    
    // Set the default score
    setScore(0);
}

void ScoreObject::setScore(int score) {
    this->score = score;
    textComponent->setText(std::to_string(score));
    textRenderComponent->createTexture(*textComponent->getSurface());
}
