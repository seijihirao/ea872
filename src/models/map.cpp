#include "../../include/models/map.h"

using namespace std;

Map::Map(string bg_url, int width, int height) : 
    bg_url(bg_url), 
    width(width), 
    height(height) {
    this->_populate(this->NUM_BLOCKS);
}

void Map::_populate(int num_blocks) {
    for (int i = 1; i < this->COLS; i += 2) {
        for(int j = 1; j < this->ROWS; j += 2) {
            this->map_matrix[i][j] = Wall;
        }
    }
}

const char* Map::getFile(){
    return bg_url.c_str();
}

int Map::getWidth() {
    return this->width;
}

int Map::getHeight() {
    return this->height;
}

int Map::getMaxX(){
    return this->COLS;
}

int Map::getMaxY(){
    return this->ROWS;
}

Coord* Map::getRealPosition(Coord coord) {
    int real_x = width/COLS * coord.getX();
    int real_y = height/ROWS * coord.getY();
    return new Coord(real_x, real_y);
}

Component Map::getComponent(Coord* coord) {
    int x = coord->getX();
    int y = coord->getY();
    return this->map_matrix[x][y];
}

