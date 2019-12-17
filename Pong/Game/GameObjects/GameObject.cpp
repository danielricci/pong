#include "Game/GameObjects/GameObject.hpp"

GameObject::GameObject(int x, int y, int width, int height) {
    this->transformComponent = new TransformComponent(x, y, width, height);
    this->addComponent(transformComponent);
}

GameObject::~GameObject() {
    for(Component* component : components) {
        delete component;
    }
}

Component* GameObject::addComponent(Component* component) {
    components.push_back(component);
    return component;
}

TransformComponent* GameObject::getTransform() const {
    return transformComponent;
}
