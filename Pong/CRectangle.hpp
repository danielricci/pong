#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <SDL.h>

class CRectangle {

public:
    CRectangle() = default;
    CRectangle(short x, short y, short width, short height);
    virtual ~CRectangle();
    
    void setX(short x) { _x = x; }
    void setY(short y) { _y = y; }
    void setWidth(short width) { _width = width; }
    void getHeight(short height) { _height = height; }
    
    short getX() const { return _x; }
    short getY() const { return _y; }
    short getWidth() const { return _width; }
    short getHeight() const { return _height; }
    
private:
    SDL_Rect _rect;
    
    short _x = 0;
    short _y = 0;
    short _width = 0;
    short _height = 0;
};
    
#endif
