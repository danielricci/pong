#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <SDL.h>

class Rectangle {
public:
    Rectangle(float x, float y, float width, float height);
    ~Rectangle();
    
    inline SDL_FRect* getRectangle() const { return rectangle; }    
private:
    void refresh();
    SDL_FRect* rectangle = new SDL_FRect();
};

#endif
