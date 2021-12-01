#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include "../../../shared/include/models/map.h"
#include "../../../shared/include/models/char.h"

using namespace std;

class Movement {
private:
  /** Character pointer */
  const shared_ptr<Char> character;

  /** Map pointer */
  const shared_ptr<Map> map;

public:
  /**
  * Creates a service to manage character movement
  *
  * @param map - map in which character will walk
  * @param character - character to move
  */
  Movement(shared_ptr<Map> map, shared_ptr<Char> character);

  /**
  * Moves character deppending on key event
  *
  * @param event - keyboard event
  */
  void move(SDL_Event event);

  /**
  * Walks upward if possible
  */
  void walkUp();

  /**
  * Walks downward if possible
  */
  void walkDown();

  /**
  * Walks left if possible
  */
  void walkLeft();

  /**
  * Walks right if possible
  */
  void walkRight();
};
