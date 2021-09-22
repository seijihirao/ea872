#ifndef MODEL_H
#define MODEL_H

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
#include <string>

using namespace std;

enum Component {
    Nothing,
    Block,
    Wall
}

class Map {
    private:
        string bg_url;
        int width, height;
        Component[][] map_matrix;

        void _populate(int num_blocks);

    public:
        Map(string bg_url, int width, int height);
        int getRealPosition(int x, int y);
        Component getComponent(int x, int y);
        int getWidth();
        int getHeight();
};

#endif
