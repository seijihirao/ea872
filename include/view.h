#ifndef VIEW_H
#define VIEW_H

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
#include <memory>
#include <iostream>
#include "model.h"

using namespace std;

class View {
    private:
        shared_ptr<Model> bg;
        shared_ptr<Model> fg;
        // SDL_Window* window;
        // SDL_Renderer* renderer;
    public:
        View(shared_ptr<Model> bg, shared_ptr<Model> fg);
        ~View();
        // SDL_Texture* render(shared_ptr<Model> model);
        void draw();
};

#endif
