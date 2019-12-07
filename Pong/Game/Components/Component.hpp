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
    virtual Type identifier() const = 0;
};
