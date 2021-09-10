#include "model.h"

using namespace std;

Model::Model(string file, int x, int y) : file(file) {
    target.x = x;
    target.y = y;
}

const char* Model::getFile() {
    return file.c_str();
}

SDL_Rect* Model::getTarget() {
    return &target;
}

int *Model::getX() {
    return &target.x;
}

void Model::moveRight() {
    target.x += 1;
}

void Model::moveLeft() {
    target.x -= 1;
}

int *Model::getY() {
    return &target.y;
}

void Model::moveUp() {
    target.y -= 1;
}

void Model::moveDown() {
    target.y += 1;
}

int *Model::getW() {
    return &target.w;
}

int *Model::getH() {
    return &target.h;
}

SDL_Texture*Model:: getTexture() {
    return texture;
}

void Model::setTexture(SDL_Texture *texture) {
    this->texture = texture;
}
