#include "../../include/models/map.h"

using namespace std;

Map::Map(string bg_url, int width, int height) :
Texture(bg_url, width, height) {
  this->target.x = 0;
  this->target.y = 0;
  this->_populate("../assets/brick.png", "../assets/block.png");
}

void Map::_populate(string brick_url, string block_url) {
  int i,j,size;
  size = NUM_BLOCKS;

  // Fill with nothing
  for (i = 0; i < this->COLS; i += 1) {
    for(j = 0; j < this->ROWS; j += 1) {
      this->map_matrix[i][j] = Nothing;
    }
  }

  // Fill Walls
  for (i = 1; i < this->COLS; i += 2) {
    for(j = 1; j < this->ROWS; j += 2) {
      this->map_matrix[i][j] = Wall;
      this->bricks.push_back(shared_ptr<Brick>(new Brick(brick_url,40*i,40*j)));
    }
  }

  // Fill blocks
  while(size > 0){
    i = rand() % (COLS-1);
    j = rand() % (ROWS-1);

    if( ((j == 0 || j == 10) && (i <= 1 || i >= 15)) || ((j == 1 || j == 9) && (i == 0 || i == 16)) ){}
    else if(this->map_matrix[i][j] == Nothing){
      this->map_matrix[i][j] = Bloc;
      this->blocks.push_back(shared_ptr<Block>(new Block(block_url,40*i,40*j)));
      size --;
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

vector<shared_ptr<Brick>> Map:: getBricks(){
  return this->bricks;
}

vector<shared_ptr<Block>> Map:: getBlocks(){
  return this->blocks;
}

void Map::setBomb_matrix(Coord coord){
  int x,y;
  x = coord.getX();
  y = coord.getY();
  this->map_matrix[x][y] = Boom;
}

Component Map:: checkComponent(int x, int y){
  return this->map_matrix[x][y];
}

void Map::setAfterExplosion(int x, int y){

  if(this->map_matrix[x][y] == Bloc){

    for(int i = 0; i < this->blocks.size(); i++){
      if((this->blocks[i]->getX() == x) && (this->blocks[i]->getY() == y))
      this->blocks[i]->destroy();
    }

    this->map_matrix[x][y] = Nothing;
  }

  else if(this->map_matrix[x][y] == Boom){
    this->map_matrix[x][y] = Nothing;
  }
}
