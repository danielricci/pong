#include "Game/GameObjects/GameOverObject.hpp"

#include "Game/Components/RenderComponent.hpp"
#include "Game/Components/TransformComponent.hpp"

GameOverObject::GameOverObject(int windowWidth, int windowHeight, SDL_Renderer& renderer) {

    textRenderComponent = new TextRenderComponent(renderer);
    addComponent(this->textRenderComponent);
    
    // Set the text, it will never change
    textComponent->setText(GAME_OVER);
    textRenderComponent->createTexture(*textComponent->getSurface());
    addComponent(this->textComponent);
    
    // Set the position of this objectm
    TransformComponent* transformComponent = this->getTransform();
    transformComponent->positionVector.x() = (windowWidth / 2) - (textComponent->getSurface()->w / 2);
    transformComponent->positionVector.y() = (windowHeight / 3) - (textComponent->getSurface()->h / 2);
    
    // Indicate that it is not a game over
    setIsGameOver(false);
}

void GameOverObject::setIsGameOver(bool isGameOver) {
    this->isGameOver = isGameOver;
    this->textRenderComponent->isVisible = isGameOver;
}
