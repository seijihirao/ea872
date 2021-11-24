#include "../../include/models/block.h"

using namespace std;

Block::Block(string wall_url, int x, int y) : Texture(wall_url,40,40){
  this->target.x = x;
  this->target.y = y;
}

int Block::getX(){
  return (this->target.x)/40;
}

int Block::getY(){
  return (this->target.y)/40;
}

void Block::destroy(){
  this->alive = false;
}

bool Block::isAlive(){
  return this->alive;
}
