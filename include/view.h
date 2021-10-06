#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>
#include "models/map.h"
#include "models/char.h"
#include "models/brick.h"
#include "controllers/movement.h"

using namespace std;

class View {
    private:
        shared_ptr<Map> map;
        shared_ptr<Char> character;
        vector<shared_ptr<Brick>> bricks;
        SDL_Window* window;
        SDL_Renderer* renderer;
        
    public:
        View(shared_ptr<Map> map, shared_ptr<Char> character);
        ~View();
        
        SDL_Texture* render(shared_ptr<Texture> texture);
        
        void construct(string url);
        void draw();
};

#endif
