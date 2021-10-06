#include "../../include/models/map.h"

using namespace std;

Map::Map(string bg_url, int width, int height) : 
    Texture(bg_url, width, height) { 
    this->target.x = 0;
    this->target.y = 0;
    this->_populate(this->NUM_BLOCKS);
}

void Map::_populate(int num_blocks) {
    // Fill with nothing
    for (int i = 0; i < this->COLS; i += 1) {
        for(int j = 0; j < this->ROWS; j += 1) {
            this->map_matrix[i][j] = Nothing;
        }
    }

    // Fill Walls
    for (int i = 1; i < this->COLS; i += 2) {
        for(int j = 1; j < this->ROWS; j += 2) {
            this->map_matrix[i][j] = Wall;
        }
    }
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

int Map::getMaxX(){
    return this->COLS;
}

int Map::getMaxY(){
    return this->ROWS;
}

