#include "Game/GameObjects/ScoreObject.hpp"

ScoreObject::ScoreObject(int x, int y, SDL_Renderer& renderer) : GameObject(x, y) {
    addComponent(textComponent);
    textRenderComponent = new TextRenderComponent(renderer);
    addComponent(textRenderComponent);
}
