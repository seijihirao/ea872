#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"
#include "coord.h"
#include "bomb.h"
#include <iostream>
#include "../../../ext/json.hpp"

using namespace std;

class Char : public Texture {
    private:
        /** position */
        Coord position;

        /** alive - player's situation (alive or dead) */
        bool alive = true;

    public:
	      NLOHMANN_DEFINE_TYPE_INTRUSIVE(Char, position, alive);
        /**
         * Create a new char sprite
         *
         * @param char_url - image file url
         * @param position - initial position
         * @param width - char width
         * @param height - char height
         */
        Char(string char_url, Coord position, int width, int height);
        
        /**
         * Create a new char sprite with width and height 40x40
         *
         * @param position - initial position
         */
        Char(Coord position);

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

        /**
         * Verify if the character is alive
         *
         *@returns true or false
         */
        bool isAlive();

        /**
         * Sets alive to false
         */
        void kill();
};
