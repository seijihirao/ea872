#ifndef CHAR_H
#define CHAR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"
#include "coord.h"

using namespace std;

class Char : public Texture {
    private:
        Coord position;

    public:
        Char(string char_url, Coord position, int width, int height);

        Coord getPosition();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};

#endif
