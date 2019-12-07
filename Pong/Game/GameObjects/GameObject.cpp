#include "Game/GameObjects/GameObject.hpp"

GameObject::GameObject(int x, int y) {
    this->transformComponent = new TransformComponent(x, y);
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
