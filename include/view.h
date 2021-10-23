#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include "models/map.h"
#include "models/char.h"
#include "models/brick.h"
#include "models/block.h"
#include "controllers/movement.h"

using namespace std;

class View {
    private:
    	/** map pointer */
        shared_ptr<Map> map;

        /** character pointer */
        shared_ptr<Char> character;

        /** sdl window */
        SDL_Window* window;

        /** sdl renderer */
        SDL_Renderer* renderer;

    public:

    	/**
    	*Create a view object with a map and player
    	*
    	*@param map - map
    	*@param character - player
    	*/
        View(shared_ptr<Map> map, shared_ptr<Char> character);

        /**
    	*Destroy view object and textures on the screen
    	*
    	*
    	*
    	*/
        ~View();

        /**
    	*Receive a texture pointer and render his texture on the screen
    	*
    	*@param texture - texture pointer (character, indestructible wall or player)
    	*@returns a sdl_texture render pointer
    	*/
        SDL_Texture* render(shared_ptr<Texture> texture);

        /**
    	*Draws textures on the screen
    	*
    	*
    	*
    	*/
        void draw();
};

#endif
