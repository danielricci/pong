#pragma once

#include "Game/Components/Component.hpp"

class TransformComponent : public Component {
public:
    TransformComponent() = default;
    TransformComponent(int x, int y) : x(x), y(y) { }
    
    void setTranslationX(int x) {
        this->x = x;
    }
    
    void setTranslationY(int y) {
        this->y = y;
    }
    
    void setTranslation(int x, int y) {
        setTranslationX(x);
        setTranslationY(y);
    }
    
    void moveTranslationX(int x) {
        setTranslationX(this->x + x);
    }
    
    void moveTranslationY(int y) {
        setTranslationY(this->y + y);
    }

    void moveTranslation(int x, int y) {
        moveTranslationX(x);
        moveTranslationY(y);
    }
    
    void getTranslation(int* outX, int* outY) {
        if(outX != nullptr) {
            *outX = this->x;
        }
        if(outY != nullptr) {
            *outY = this->y;
        }
    }
    
    virtual Type getIdentifier() const override {
        return Component::Type::TransformComponent;
    }
    
private:
    int x { 0 };
    int y { 0 };
};
