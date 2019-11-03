#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <SDL.h>

class Rectangle {
public:
    Rectangle(int x, int y, int width, int height);
    ~Rectangle() { delete rectangle; }
    SDL_Rect* getRectangle() const { return rectangle; }
private:
    SDL_Rect* rectangle;
};

#endif
