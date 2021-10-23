#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include "texture.h"
#include "coord.h"
#include "brick.h"
#include "block.h"

using namespace std;

/**
 * Map component
 */
enum Component {
    /** Nothing there, can walk */
    Nothing,

    /** Destructable block */
    Bloc,

    /** Undestructable block */
    Wall
};

class Map : public Texture{
    private:
        /** Map matrix size  */
        int COLS=17, ROWS=11;

        /** Number of destructable blocks */
        int NUM_BLOCKS = 30;

        /** Map matrix with components */
        Component map_matrix[17][11];

        /** Max size */
        int matrix_width, matrix_height;

        /** vector with indestructive walls*/
        vector<shared_ptr<Brick>> bricks;

        /** vector with destructive walls*/
        vector<shared_ptr<Block>> blocks;

    public:
        /**
         * Creates the map object with delimiters and background
         *
         * @param bg_url - bg file url
         * @param width - window width in pixels
         * @param height - windeo height in pixels
         */
        Map(string bg_url, int width, int height);

        /**
         * Gets maximum X position on matrix
         *
         * @returns matrix x size
         */
        int getMaxX();

        /**
         * Gets maximum Y position on matrix
         *
         * @returns matrix y size
         */
        int getMaxY();

        /**
         * Gets maximum X position on matrix
         *
         * @returns matrix x size
         */
        vector<shared_ptr<Brick>> getBricks();

        /**
         * Gets maximum X position on matrix
         *
         * @returns matrix x size
         */
        vector<shared_ptr<Block>> getBlocks();

        /**
         * Gets position in pixel from coordinate
         *
         * @param coord - matrix position
         *
         * @returns coordinate in pixels
         */
        Coord* getRealPosition(Coord coord);

        /**
         * Gets which component is in this coordinate
         *
         * @param coord - coordinate to get from
         *
         * @returns component found
         */
        Component getComponent(Coord* coord);


        /**
         * Populates matrix with components
         */
        void _populate(string brick_url, string block_url);
};

#endif
