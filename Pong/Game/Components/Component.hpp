#pragma once

class Component {
public:
    virtual ~Component() = default;
    enum class Type {
        TransformComponent,
        InputComponent,
        PaddleInputComponent,
        RenderComponent
    };
    virtual Type getIdentifier() const = 0;
};
