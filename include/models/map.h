#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "texture.h"
#include "coord.h"

using namespace std;

enum Component {
    Nothing,
    Block,
    Wall
};

class Map : public Texture{
    private:
        int COLS=17, ROWS=11;
        int NUM_BLOCKS = 20;

        Component map_matrix[17][11];
        int matrix_width, matrix_height;

        void _populate(int num_blocks);

    public:
        Map(string bg_url, int width, int height);

        int getMaxX();
        int getMaxY();

        Coord* getRealPosition(Coord coord);
        Component getComponent(Coord* coord);
};

#endif
