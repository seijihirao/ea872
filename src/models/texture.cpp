#include "../../include/models/texture.h"

using namespace std;

SDL_Rect* Texture::getTarget() {
    return &target;
}

void Texture::setTarget(SDL_Rect target) {
    this->target = target;
}

SDL_Texture* Texture::getTexture() {
    return this->texture;
}

void Texture::setTexture(SDL_Texture* texture) {
    this->texture = texture;
}

int* Texture:: getW(){
    return &target.w;
}

int* Texture:: getH(){
    return &target.h;
}
