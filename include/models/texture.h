#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Texture {
    protected:
        SDL_Rect* target;
        SDL_Texture* texture;

    public:
        SDL_Rect* getTarget();
        void setTarget(SDL_Rect* target);
        SDL_Texture* getTexture();
        void setTexture(SDL_Texture* texture);

};

#endif
