#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"
#include "coord.h"
#include "bomb.h"
#include "../ext/json.hpp"

using namespace std;

class Char : public Texture {
    private:
        /** position - TODO: move to Texture class */
        Coord position;

    public:
	    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Char, position);
        /**
         * Create a new char sprite on position 0, 0
         *
         * @param char_url - image file url
         * @param width - char width
         * @param height - char height
         */
        Char(string char_url, Coord position, int width, int height);

        /**
         * Gets current position on matrix
         */
        Coord getPosition();

        /**
         * Sets current position on matrix
         */
        void setPosition(Coord position);

        /**
         * Moves charater upward
         */
        void moveUp();

        /**
         * Moves charater downward
         */
        void moveDown();

        /**
         * Moves charater left
         */
        void moveLeft();

        /**
         * Moves charater right
         */
        void moveRight();
};
