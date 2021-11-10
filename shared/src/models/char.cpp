#include "../../include/models/char.h"

using namespace std;

Char::Char(string char_url, Coord position, int width, int height) :
    Texture(char_url, width, height),
    position(position) {
    this->target.x = 0;
    this->target.y = 0;
}

Coord Char::getPosition() {
    return this->position;
}

void Char::setPosition(Coord position) {
    this->position = position;
}

void Char::moveUp() {
    this->position.setY(this->position.getY() - 1);
    this->target.y += -40;
}

void Char::moveDown() {
    this->position.setY(this->position.getY() + 1);
    this->target.y += 40;
}

void Char::moveLeft() {
    this->position.setX(this->position.getX() - 1);
    this->target.x += -40;
}

void Char::moveRight() {
    this->position.setX(this->position.getX() + 1);
    this->target.x += 40;
}
