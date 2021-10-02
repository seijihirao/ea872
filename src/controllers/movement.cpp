#include "../../include/controllers/movement.h"
#include "../../include/models/map.h"
#include <iostream>

using namespace std;

Movement::Movement(shared_ptr<Map> map, shared_ptr<Char> character) : map(map), character(character) {
	state = SDL_GetKeyboardState(nullptr);
}

void Movement::move(){
    SDL_PumpEvents(); // atualiza estado do teclado
    if (state[SDL_SCANCODE_LEFT]) walkLeft();
    if (state[SDL_SCANCODE_RIGHT]) walkRight();
    if (state[SDL_SCANCODE_UP]) walkUp();
    if (state[SDL_SCANCODE_DOWN]) walkDown();
}

void Movement::walkLeft() {

    if (this->character->getPosition().getX() <= 0) {
        return;
    }
    if (this->map->getComponent(new Coord(this->character->getPosition().getX() - 1, this->character->getPosition().getY())) != Nothing) {
        return;
    }
    this->character->moveLeft();
}

void Movement::walkRight() {
    if (this->character->getPosition().getX() >= this->map->getMaxX() - 1) {
        return;
    }
    if (this->map->getComponent(new Coord(this->character->getPosition().getX() + 1, this->character->getPosition().getY())) != Nothing) {
        return;
    }
    this->character->moveRight();
}

void Movement::walkUp() {
    if (this->character->getPosition().getY() <= 0) {
        return;
    }
    if (this->map->getComponent(new Coord(this->character->getPosition().getX(), this->character->getPosition().getY() - 1)) != Nothing) {
        return;
    }
    this->character->moveUp();
}

void Movement::walkDown() {
    if (this->character->getPosition().getY() >= this->map->getMaxY() - 1) {
        return;
    }
    if (this->map->getComponent(new Coord(this->character->getPosition().getX(), this->character->getPosition().getY() + 1)) != Nothing) {
        return;
    }
    this->character->moveDown();
}
