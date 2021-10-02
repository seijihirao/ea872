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
        Texture(string url, int width, int height);

        SDL_Rect* getTarget();
        void setTarget(SDL_Rect target);
        SDL_Texture* getTexture();
        void setTexture(SDL_Texture* texture);
        
        const char* getFile();
        
        int* getWidth();
        int* getHeight();

};

#endif
