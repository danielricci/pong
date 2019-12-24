#include "Game/GameObjects/ScoreObject.hpp"

ScoreObject::ScoreObject(int x, int y) : GameObject(x, y, WIDTH, HEIGHT) {
    addComponent(renderComponent);
}
