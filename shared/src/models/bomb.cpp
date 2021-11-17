#include "../../include/models/bomb.h"

using namespace std;

Bomb::Bomb(string char_url, Coord position, int width, int height) :
    Texture(char_url, width, height),
    position(position) {
    this->target.x = 40 * position.getX();
    this->target.y = 40 * position.getY();
}

Coord Bomb:: getPosition(){
  return this->position;
}
