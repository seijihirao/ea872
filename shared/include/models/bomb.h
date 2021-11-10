#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"
#include "coord.h"

using namespace std;

class Bomb : public Texture{
    private:
        /** position: move to Texture class */
        Coord position;

    public:
	    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Bomb, position);

        /**
    	 * Create a bomb object with his target on the screen
    	 *
    	 * @param bomb_url - bomb sprite image url
    	 * @param position - current bomb position
    	 * @param width - sprite width
    	 * @param height - sprite height
    	 */
        Bomb(string bomb_url, Coord position, int width, int height);
};
