#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float width, float height) {
    rectangle->x = x;
    rectangle->y = y;
    rectangle->w = width;
    rectangle->h = height;
}

Rectangle::~Rectangle() {
    delete rectangle;
}
