#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include "../../shared/include/models/map.h"
#include "../../shared/include/models/char.h"
#include "../../shared/include/models/brick.h"
#include "../../shared/include/models/block.h"

using namespace std;

class View {
private:
  /** map pointer */
  shared_ptr<Map> map;

  /** character pointer */
  shared_ptr<vector<shared_ptr<Char>>> characters;

  /** bomb list pointer */
  vector<shared_ptr<Bomb>> bombs;

  /** sdl window */
  SDL_Window* window;

  /** sdl renderer */
  SDL_Renderer* renderer;

  /** Current rendered players */
  int rendered_players = 0;

public:

  /**
  * Create a view object with a map and player
  *
  * @param map - map
  * @param character - player
  */
  View(shared_ptr<Map> map, shared_ptr<vector<shared_ptr<Char>>> characters);

  /**
  * Destroy view object and textures on the screen
  *
  *
  *
  */
  ~View();

  /**
  * Receive a texture pointer and render his texture on the screen
  *
  * @param texture - texture pointer (character, indestructible wall or player)
  * @returns a sdl_texture render pointer
  */
  SDL_Texture* render(shared_ptr<Texture> texture);

  /**
  * Draws textures on the screen
  */
  void draw();

  /**
  * Renders bomb on map
  *
  * @param bomb - pointer to bomb to render
  */
  void renderBomb(shared_ptr<Bomb> bomb);

  /**
  * Renders new players on map
  *
  * @param characters - list of players to renders
  */
  void renderChars(shared_ptr<vector<shared_ptr<Char>>> characters);
};
