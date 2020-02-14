#pragma once

#include <list>

class Component {
public:
    virtual ~Component() {
        for(Component* component : components) {
            delete component;
        }
        components.clear();
    }
    template<typename T> T* getComponent() {
        T* myComponent { dynamic_cast<T*>(this) };
        if(myComponent == nullptr) {
            for(Component* component : components) {
                myComponent = dynamic_cast<T*>(component);
                if(myComponent != nullptr) {
                    break;
                }
            }
        }
        return myComponent;
    }
    
    Component* addComponent(Component* component) {
        if(component != nullptr) {
            components.push_back(component);
        }
        return component;
    }
private:
    std::list<Component*> components;
};
