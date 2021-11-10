#include "../../include/models/block.h"

using namespace std;

Block::Block(string wall_url, int x, int y) : Texture(wall_url,40,40){
  this->target.x = x;
  this->target.y = y;
}
