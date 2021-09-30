#include "../../include/models/char.h"

using namespace std;

Char::Char(string char_url, Coord position) : 
    char_url(char_url), 
    position(position) {
}

Coord Char::getPosition() {
    return this->position;
}

void Char::moveUp() {
    this->position.setY(this->position.getY() - 1);
}

void Char::moveDown() {
    this->position.setY(this->position.getY() + 1);
}

void Char::moveLeft() {
    this->position.setX(this->position.getX() - 1);
}

void Char::moveRight() {
    this->position.setX(this->position.getX() + 1);
}

