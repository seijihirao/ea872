#ifndef BOMB_H
#define BOMB_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"

using namespace std;

class Bomb : public Texture{
      public:

        /**
    	*Create a bomb object with his target on the screen
    	*
    	*@param x - target x from screen
    	*@param y - target y from screen
    	*/
      Bomb(string bomb_url, int x, int y);
};

#endif
