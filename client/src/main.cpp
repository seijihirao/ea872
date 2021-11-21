#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <thread>
#include "../include/view.h"
#include "../include/controllers/movement.h"
#include "../include/controllers/bomb_control.h"
#include "../include/controllers/save.h"
#include "../include/controllers/sync.h"

using namespace std;

void mainLoop(shared_ptr<Map> map,
              shared_ptr<Char> character) {

  shared_ptr<View> view (new View(map, character));
  
shared_ptr<Movement> movement (new Movement(map, character));
  shared_ptr<BombControl> bomb_control (new BombControl(map, character));

  bool run = true;

  SDL_Event event; // eventos discretos

  // Main loop
  while(run) {

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        run = false;
      }
    }

    if(character->isAlive()){
      movement->move(event);
      shared_ptr<Bomb> bomb = bomb_control->listen(event);
      if(bomb != nullptr) {
        view->renderBomb(bomb);
      }
    }

    // save->save();

    view->draw();
    this_thread::sleep_for(100ms);
  }
}

void syncData(shared_ptr<Sync> sync) {
  while (true) {
    sync->sync();
    this_thread::sleep_for(1000ms);
  }
}

int main() {

  // Inicializando o subsistema de video do SDL
  if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
    std::cout << SDL_GetError();
    return 1;
  }

  // MVC
  Coord position = Coord(0,0);
  shared_ptr<Map> map (new Map("../assets/bg.jpg", 680, 440));
  shared_ptr<Char> character (new Char("../assets/player.png", position, 40, 40));
  shared_ptr<Save> save (new Save(map, character));
  //save->load();

  // Server
  shared_ptr<Sync> sync (new Sync(map, character));
  thread sync_data (syncData, sync);
  
  // Main Loop
  mainLoop(map, character);

  return 0;
}
