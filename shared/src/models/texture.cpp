#include "../../include/models/texture.h"

using namespace std;

Texture::Texture(string url, int width, int height) :
url(url),
width(width),
height(height) {
  this->target.w = width;
  this->target.h = height;
}

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

const char* Texture::getFile(){
  return this->url.c_str();
}

int* Texture:: getWidth(){
  return &this->width;
}

int* Texture:: getHeight(){
  return &this->width;
}
