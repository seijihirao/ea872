#include "../../include/models/texture.h"

using namespace std;

SDL_Rect Map::getTarget() {
    return this.target;
}

void Map::setTarget(SDL_Rect target) {
    this.target = target;
}

SDL_Texture* Map::getTexture() {
    return this.texture;
}

void Map::setTexture(SDL_Texture* texture) {
    this.texture = texture;
}
