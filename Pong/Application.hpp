#ifndef Application_hpp
#define Application_hpp

#include <SDL.h>

class Application {
  
public:
    Application(const char* title, int width, int height);
    ~Application();
    void initalize();
    void handleEvents();
    void update();
    void render();
    bool isRunning() const { return running; }

    
private:
    const char* title { nullptr };
    const int width { 0 };
    const int height { 0 };
    bool running { false };
    
    SDL_Window* window { nullptr };
    SDL_Renderer* renderer { nullptr };
};

#endif
