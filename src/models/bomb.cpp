#include "../../include/models/bomb.h"

using namespace std;

Bomb::Bomb(string bomb_url, int x, int y) : Texture(bomb_url,40,40){
  this->target.x = x;
  this->target.y = y;
}
