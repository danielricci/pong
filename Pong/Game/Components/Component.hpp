#pragma once

class Component {
public:
    virtual ~Component() = default;
    enum class Type {
        TransformComponent          = 1 << 0,
        InputComponent              = 1 << 1
    };
    virtual Type getIdentifier() const = 0;
};
