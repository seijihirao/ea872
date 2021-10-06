#include "../../include/controllers/movement.h"
#include "../../include/models/map.h"
#include <iostream>

using namespace std;

Movement::Movement(shared_ptr<Map> map, shared_ptr<Char> character) : map(map), character(character) {
}

void Movement::move(SDL_Event event){
    switch( event.type ){
        case SDL_KEYDOWN:
            // Key was pressed time to check which key
            switch( event.key.keysym.sym ){
	            case SDLK_LEFT:
		            this->walkLeft();
                    break;
	            case SDLK_RIGHT:
		            this->walkRight();
		            break;
	            case SDLK_UP:
		            this->walkUp();
		            break;
	            case SDLK_DOWN:
		            this->walkDown();
		            break;
	            default:
		            break;
            }
            break;
        case SDL_KEYUP:
            break;
        default:
            break;
    }	
}

void Movement::walkLeft() {

    if (this->character->getPosition().getX() <= 0) {
        return;
    }
    if (this->map->getComponent(
	new Coord(this->character->getPosition().getX() - 1, this->character->getPosition().getY())) != Nothing) {
        return;
    }
    this->character->moveLeft();
}

void Movement::walkRight() {
    if (this->character->getPosition().getX() >= this->map->getMaxX() - 1) {
        return;
    }
    if (this->map->getComponent(
	new Coord(this->character->getPosition().getX() + 1, this->character->getPosition().getY())) != Nothing) {
        return;
    }
    this->character->moveRight();
}

void Movement::walkUp() {
    if (this->character->getPosition().getY() <= 0) {
        return;
    }
    if (this->map->getComponent(
	new Coord(this->character->getPosition().getX(), this->character->getPosition().getY() - 1)) != Nothing) {
        return;
    }
    this->character->moveUp();
}

void Movement::walkDown() {
    if (this->character->getPosition().getY() >= this->map->getMaxY() - 1) {
        return;
    }
    if (this->map->getComponent(
	new Coord(this->character->getPosition().getX(), this->character->getPosition().getY() + 1)) != Nothing) {
        return;
    }
    this->character->moveDown();
}
