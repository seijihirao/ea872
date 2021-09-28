#ifndef MAP_H
#define MAP_H

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
#include <string>
#include "texture.h"
#include "coord.h"

using namespace std;

enum Component {
    Nothing,
    Block,
    Wall
}

class Map : Texture{
    private:
        int COLS=16, ROWS=10;
        int NUM_BLOCKS = 20;

        string bg_url;
        int width, height;
        Component map_matrix[16][10];
        int matrix_width, matrix_height;

        void _populate(int num_blocks);

    public:
        Map(string bg_url, int width, int height);

        int getWidth();
        int getHeight();

        int getMaxX();
        int getMaxY();

        Coord getRealPosition(Coord coord);
        Component getComponent(Coord coord);
};

#endif
