#ifndef BRICK_H
#define BRICK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"

using namespace std;

class Brick : public Texture{
      public:
        Brick(string brick_url, int x, int y);
};

#endif
