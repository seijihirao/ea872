#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "texture.h"
#include "coord.h"

using namespace std;

/**
 * Map component
 */
enum Component {
    /** Nothing there, can walk */
    Nothing,

    /** Destructable block */
    Block,
    
    /** Undestructable block */
    Wall
};

class Map : public Texture{
    private:
        /** Map matrix size  */
        int COLS=17, ROWS=11;
        
        /** Number of destructable blocks */
        int NUM_BLOCKS = 20;

        /** Map matrix with components */
        Component map_matrix[17][11];

        /** Max size */
        int matrix_width, matrix_height;

        /**
         * Populates matrix with components
         */
        void _populate(int num_blocks);

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
};

#endif
