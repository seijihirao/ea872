#ifndef MOVEMENT_H
#define MOVEMENT_H

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
#include <memory>
#include "map.h"
#include "char.h"

using namespace std;

class Movement {
    private:
        const shared_ptr<Char> character;
        const shared_ptr<Map> map;

    public:
        Movement(shared_ptr<Map> map, shared_ptr<Char> character);
        void walkUp();
        void walkDown();
        void walkLeft();
        void walkRight();
};

#endif
