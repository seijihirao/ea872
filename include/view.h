#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <iostream>
#include "models/map.h"
#include "controllers/movement.h"

using namespace std;

class View {
    private:
        shared_ptr<Map> map;
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        View(shared_ptr<Map> map);
        ~View();
        
        void addChar(shared_ptr<Char> character);
        SDL_Texture* render(shared_ptr<Model> model);

        listenMovement(shared_ptr<Movement> movement);

        void draw();
};

#endif
