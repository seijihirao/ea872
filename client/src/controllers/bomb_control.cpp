#include "../../include/controllers/bomb_control.h"
#include <iostream>

using namespace std;

BombControl::BombControl(shared_ptr<Map> map, shared_ptr<Char> character) : map(map), character(character) {
}

shared_ptr<Bomb> BombControl::listen(SDL_Event event){
    switch( event.type ){
        case SDL_KEYDOWN:
            // Key was pressed time to check which key
            switch( event.key.keysym.sym ){
                case SDLK_LSHIFT:
                    return this->createNewBomb();
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
    return nullptr;
}

shared_ptr<Bomb> BombControl::createNewBomb(){
    shared_ptr<Bomb> bomb(new Bomb("../assets/bomb.png", this->character->getPosition(), 40, 40));
    return bomb;
}

shared_ptr<Bomb> BombControl::explode(shared_ptr<Bomb> bomb){
    return bomb;
}

