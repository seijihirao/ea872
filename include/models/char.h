#ifndef CHAR_H
#define CHAR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "texture.h"
#include "coord.h"

using namespace std;

class Char : public Texture {
    private:
        SDL_Rect* target;
        SDL_Texture* texture;

    public:
        SDL_Rect* getTarget();
        void setTarget(SDL_Rect* target);
        SDL_Texture* getTexture();
        void setTexture(SDL_Texture* texture);
};

#endif
