#ifndef BLOCK_H
#define BLOCK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"

using namespace std;

class Block : public Texture{
      public:

        /**
    	*Create a destructible wall object with his target on the screen
    	*
    	*@param x - target x from screen
    	*@param y - target y from screen
    	*/
        Block(string wall_url, int x, int y);
};

#endif
