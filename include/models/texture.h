#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

class Texture {
    protected:
        SDL_Rect target;
        SDL_Texture* texture;
	
	    string url;
        int width, height;

    public:
        /**
         * Creates a sprite from an url
         *
         * @param url - sprite file url
         * @param width - sprite width
         * @param height - sprite height
         */
        Texture(string url, int width, int height);

        /**
         * Gets SDL target
         *
         * @returns SDL target
         */
        SDL_Rect* getTarget();

        /**
         * Sets SDL target
         *
         * @param target - SDL target
         */
        void setTarget(SDL_Rect target);

        /**
         * Gets SDL texture
         *
         * @returns SDL texture
         */
        SDL_Texture* getTexture();

        /**
         * Sets SDL texture
         *
         * @param texture - SDL texture
         */
        void setTexture(SDL_Texture* texture);
        
        /**
         * Gets sprite filename
         *
         * @returns file url
         */
        const char* getFile();
        
        /**
         * Gets target width
         *
         * @returns sprite width
         */
        int* getWidth();
        
        /**
         * Gets target height
         *
         * @returns sprite height
         */
        int* getHeight();

};

#endif
