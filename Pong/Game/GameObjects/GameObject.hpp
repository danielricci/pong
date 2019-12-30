#pragma once

#include "Game/Components/Component.hpp"
#include "Game/Components/TransformComponent.hpp"

#include <list>

class GameObject {
public:

    virtual ~GameObject();

    template<typename T> T* getComponent() const {
        T* myComponent { nullptr };
        for(Component* component : components) {
            myComponent = component->getComponent<T>();
            if(myComponent != nullptr) {
                break;
            }
        }
        return myComponent;
    }
    
    Component* addComponent(Component* component);
    TransformComponent* getTransform() const;

protected:
    GameObject(int x = 0, int y = 0, int width = 0, int height = 0);
    
private:
    std::list<Component*> components;
    TransformComponent* transformComponent { nullptr };
};
