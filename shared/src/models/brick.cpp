#include "../../include/models/brick.h"

using namespace std;

Brick::Brick(string brick_url, int x, int y) : Texture(brick_url,40,40){
  this->target.x = x;
  this->target.y = y;
}
