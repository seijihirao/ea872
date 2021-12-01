#include "../../include/controllers/bomb_control.h"
#include <iostream>
#include <thread>

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

void explode(shared_ptr<Bomb> bomb, shared_ptr<Char> character, shared_ptr<Map> map){

  this_thread::sleep_for(2000ms);

  int x,y,aux1, aux2;
  x = bomb->getPosition().getX();
  y = bomb->getPosition().getY();

  bomb->setDestroyed();

  if(character->getPosition().getX() == x || character->getPosition().getX() == x+1 || (character->getPosition().getX() == x+2  && map->checkComponent(x+1,y) != Wall)){
    if(character->getPosition().getY() == y || character->getPosition().getY() == y+1 || (character->getPosition().getY() == y+2 && map->checkComponent(x,y+1) != Wall))
    character->kill();
  }

  if(x-2 >= 0 || x-1 >= 0){
    if((character->getPosition().getX() == x-2 && map->checkComponent(x-1,y) != Wall)  || character->getPosition().getX() == x-1)
    if(character->getPosition().getY() == y)
    character->kill();
  }

  if(y-2 >= 0 || y-1 >= 0){
    if((character->getPosition().getY() == y-2 && map->checkComponent(x,y-1) != Wall)  || character->getPosition().getY() == y-1)
    if(character->getPosition().getX() == x)
    character->kill();
  }

  if(y+1 < map->getMaxY()){
    map->setAfterExplosion(x,y+1);
    if(y+2 < map->getMaxY() && map->checkComponent(x,y+1) != Wall)
    map->setAfterExplosion(x,y+2);
  }

  if(y-1 > 0){
    map->setAfterExplosion(x,y-1);
    if(y-2 > 0 && map->checkComponent(x,y-1) != Wall)
    map->setAfterExplosion(x,y-2);
  }

  if(x+1 < map->getMaxX()){
    map->setAfterExplosion(x+1,y);
    if(x+2 < map->getMaxX() && map->checkComponent(x+1,y) != Wall)
    map->setAfterExplosion(x+2,y);
  }

  if(x-1 > 0){
    map->setAfterExplosion(x-1,y);
    if(x-2 > 0 && map->checkComponent(x-1,y) != Wall)
    map->setAfterExplosion(x-2,y);
  }

  map->setAfterExplosion(x,y);

}


shared_ptr<Bomb> BombControl::createNewBomb(){

  shared_ptr<Bomb> bomb(new Bomb("../assets/bomb.png", this->character->getPosition(), 40, 40));
  this->map->setBomb_matrix(this->character->getPosition());

  thread t_explode(explode,bomb,this->character,this->map);
  t_explode.detach();

  return bomb;
}
