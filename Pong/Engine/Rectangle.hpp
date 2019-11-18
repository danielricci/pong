#pragma once

#include <SDL.h>

class Rectangle {
public:
    Rectangle(int x, int y, int width, int height) {
        rectangle = new SDL_Rect();
        rectangle->x = x;
        rectangle->y = y;
        rectangle->w = width;
        rectangle->h = height;
    }
    ~Rectangle() { delete rectangle; }
    SDL_Rect* getRectangle() const { return rectangle; }
private:
    SDL_Rect* rectangle;
};
