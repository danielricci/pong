#include <SDL.h>
#include "Application.hpp"

int main(int argc, char** argv) {

    Application* application = new Application("Pong", 1280, 1024);
    application->initalize();
    
    while(application->isRunning()) {
        application->handleEvents();
        application->update();
        application->render();
    }
    
    delete application;
}
