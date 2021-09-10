#ifndef MODEL_H
#define MODEL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

class Model {
    private:
        string file;
        SDL_Rect target;
        SDL_Texture* texture;

    public:
        Model(string file, int x, int y);
        const char *getFile();
        SDL_Rect *getTarget();
        int *getX();
        void moveRight();
        void moveLeft();
        int *getY();
        void moveUp();
        void moveDown();
        int *getW();
        int *getH();
        SDL_Texture* getTexture();
        void setTexture(SDL_Texture *texture);

};

#endif
