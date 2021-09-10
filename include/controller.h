#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include "model.h"

using namespace std;

class FGController {
    private:
        const Uint8* state;
        const shared_ptr<Model> fg;

    public:
        FGController(shared_ptr<Model> fg);
        void move();
};

#endif
