#include "Game/GameObjects/GameObject.hpp"

GameObject::GameObject() {
    addComponent(transformComponent);
}

GameObject::GameObject(int x, int y) : GameObject() {
    transformComponent->setTranslation(x, y);
}

GameObject::~GameObject() {
    for(Component* component : components) {
        delete component;
    }
}
