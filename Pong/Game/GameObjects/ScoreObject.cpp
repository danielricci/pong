#include "Game/GameObjects/ScoreObject.hpp"

ScoreObject::ScoreObject(int x, int y, SDL_Renderer& renderer) : GameObject(x, y) {
    addComponent(textComponent);
    // TODO: Can we get the renderer associated to the world instead of having it passed here?
    textRenderComponent = new TextRenderComponent(renderer);
    addComponent(textRenderComponent);
}

void ScoreObject::setPaddleObject(const PaddleObject& paddleObject) {
    this->paddleObject = &paddleObject;
}
