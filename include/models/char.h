#ifndef CHAR_H
#define CHAR_H

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
#include <string>
#include "texture.h"
#include "coord.h"

using namespace std;

class Char : Texture {
    private:
        string char_url;
        Coord position;

    public:
        Map(string char_url, Coord position);

        Coord getPosition();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};

#endif
