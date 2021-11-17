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
  this->map->setBomb_matrix(this->character->getPosition());

  return this->explode(bomb); //MODIFICAR DEPOIS PARA RETONAR SÓ A BOMBA, NÃO A EXPLOSÃO
}

shared_ptr<Bomb> BombControl::explode(shared_ptr<Bomb> bomb){
  int x,y;
  x = bomb->getPosition().getX();
  y = bomb->getPosition().getY();

  if(this->character->getPosition().getX() == x || this->character->getPosition().getX() == x+1 || this->character->getPosition().getX() == x+2)
    if(this->character->getPosition().getY() == y || this->character->getPosition().getY() == y+1 || this->character->getPosition().getY() == y+2)
      this->character->kill();


  if(y+1 < this->map->getMaxY()){
    this->map->setAfterExplosion(x,y+1);
    if(y+2 < this->map->getMaxY() && this->map->checkComponent(x,y+1) != Wall)
      this->map->setAfterExplosion(x,y+2);
  }

  if(y-1 > 0){
    this->map->setAfterExplosion(x,y-1);
    if(y-2 > 0 && this->map->checkComponent(x,y-1) != Wall)
      this->map->setAfterExplosion(x,y-2);
  }

  if(x+1 < this->map->getMaxX()){
    this->map->setAfterExplosion(x+1,y);
    if(x+2 < this->map->getMaxX() && this->map->checkComponent(x+1,y) != Wall)
      this->map->setAfterExplosion(x+2,y);
  }

  if(x-1 > 0){
    this->map->setAfterExplosion(x-1,y);
    if(x-2 > 0 && this->map->checkComponent(x-1,y) != Wall)
      this->map->setAfterExplosion(x-2,y);
  }

  this->map->setAfterExplosion(x,y);

  return nullptr;
}
