#include "../../include/constrollers/movement.h"
#include "../../include/models/map.h"

using namespace std;

Movement::Movement(shared_ptr<Map> map, shared_ptr<Char> character) : map(map), character(character) {
}

void Movement::walkLeft() {
    if (this.character->getPosition().getX() <= 0) {
        return;
    }
    if (this.map.getComponent(new Coord(this.character->getPosition().getX() - 1, this.character->getPosition().getY())) != Component.NOTHING) {
        return
    }
    this.character.moveLeft();
}

void Movement::walkRight() {
    if (this.character->getPosition().getX() >= this.map.getMaxX() - 1) {
        return;
    }
    if (this.map.getComponent(new Coord(this.character->getPosition().getX() + 1, this.character->getPosition().getY())) != Component.NOTHING) {
        return
    }
    this.character.moveRight();
}

void Movement::walkUp() {
    if (this.character->getPosition().getY() <= 0) {
        return;
    }
    if (this.map.getComponent(new Coord(this.character->getPosition().getX(), this.character->getPosition().getY() - 1)) != Component.NOTHING) {
        return
    }
    this.character.moveUp();
}

void Movement::walkDown() {
    if (this.character->getPosition().getY() >= this.map.getMaxY() - 1) {
        return;
    }
    if (this.map.getComponent(new Coord(this.character->getPosition().getX(), this.character->getPosition().getY() + 1)) != Component.NOTHING) {
        return
    }
    this.character.moveDown();
}
