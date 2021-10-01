#include "../../include/models/char.h"

using namespace std;

Char::Char(string char_url, Coord position) : 
    char_url(char_url), 
    position(position) {
    this->target.x = 0;
    this->target.y = 0;
}

const char* Char::getFile(){
    return char_url.c_str();
}

Coord Char::getPosition() {
    return this->position;
}

void Char::moveUp() {
    this->position.setY(this->position.getY() - 1);
    this->target.y += -1;
}

void Char::moveDown() {
    this->position.setY(this->position.getY() + 1);
    this->target.y += 1;
}

void Char::moveLeft() {
    this->position.setX(this->position.getX() - 1);
    this->target.x += -1;
}

void Char::moveRight() {
    this->position.setX(this->position.getX() + 1);
    this->target.x += 1;
}

