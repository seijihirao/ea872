#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"

using namespace std;

class Brick : public Texture{
public:

  /**
  *Create a indestructible wall object with his target on the screen
  *
  *@param x - target x from screen
  *@param y - target y from screen
  */
  Brick(string brick_url, int x, int y);
};
