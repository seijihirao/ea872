#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include "texture.h"
#include "coord.h"
#include "brick.h"
#include "block.h"
#include "../../../ext/json.hpp"

using namespace std;

/**
* Map component
*/
enum Component {
  /** Nothing there, can walk */
  Nothing,

  /** Destructable block */
  Bloc,

  /** Undestructable block */
  Wall,

  /* bomb */
  Boom
};

class Map : public Texture{
private:
  /** Map matrix size  */
  int COLS=17, ROWS=11;

  /** Number of destructable blocks */
  int NUM_BLOCKS = 30;

  /** Map matrix with components */
  Component map_matrix[17][11];

  /** Max size */
  int matrix_width, matrix_height;

  /** vector with indestructive walls*/
  vector<shared_ptr<Brick>> bricks;

  /** vector with destructive walls*/
  vector<shared_ptr<Block>> blocks;

public:
  /**
  * Creates the map object with delimiters and background
  *
  * @param bg_url - bg file url
  * @param width - window width in pixels
  * @param height - windeo height in pixels
  */
  Map(string bg_url, int width, int height);

  /**
  * Gets maximum X position on matrix
  *
  * @returns matrix x size
  */
  int getMaxX();

  /**
  * Gets maximum Y position on matrix
  *
  * @returns matrix y size
  */
  int getMaxY();

  /**
  * Gets brick vector
  *
  * @returns vector brick
  */
  vector<shared_ptr<Brick>> getBricks();

  /**
  * Gets mblock vector
  *
  * @returns vector block
  */
  vector<shared_ptr<Block>> getBlocks();

  /**
  * Gets position in pixel from coordinate
  *
  * @param coord - matrix position
  *
  * @returns coordinate in pixels
  */
  Coord* getRealPosition(Coord coord);

  /**
  * Gets which component is in this coordinate
  *
  * @param coord - coordinate to get from
  *
  * @returns component found
  */
  Component getComponent(Coord* coord);


  /**
  * Populates matrix with components
  */
  void _populate(string brick_url, string block_url);


  /**
  * Sets a bomb in matrix
  */
  void setBomb_matrix(Coord coord);

  /**
  * Check the type of component from matrix
  *
  *@param x - x cordinate
  *@param y - y coordinate
  *
  *@returns component
  */
  Component checkComponent(int x, int y);

  /**
  * If bomb explodes a "Bloc", turns into "Nothing"
  *
  * @param x - coordinate x where happens explosion
  * @param y - coordinate y where happens explosion
  */
  void setAfterExplosion(int x, int y);
};
