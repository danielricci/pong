#include "Rectangle.hpp"

Rectangle::Rectangle(int x, int y, int width, int height) {
    rectangle = new SDL_Rect();
    rectangle->x = x;
    rectangle->y = y;
    rectangle->w = width;
    rectangle->h = height;
}
