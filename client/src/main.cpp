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
  shared_ptr<vector<shared_ptr<Char>>> characters,
  shared_ptr<Sync> sync) {

    while (!sync->hasPlayerNumber()) {
      this_thread::sleep_for(1000ms);
    }

    cout << "Started game! Player number: " << sync->getPlayerNumber() << endl;

    shared_ptr<View> view (new View(map, characters));

    cout << "View initialized!" << endl;

    shared_ptr<Char> character = (*characters)[sync->getPlayerNumber()];
    shared_ptr<Movement> movement (new Movement(map, character));
    shared_ptr<BombControl> bomb_control (new BombControl(map, character));

    cout << "Controllers initialized!" << endl;

    bool run = true;

    SDL_Event event; // eventos discretos

    // Main loop
    while(run) {

      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
          run = false;
        }
      }

      if((*characters)[sync->getPlayerNumber()]->isAlive()){
        movement->move(event);
        shared_ptr<Bomb> bomb = bomb_control->listen(event);
        if(bomb != nullptr) {
          view->renderBomb(bomb);
        }
      }

      view->draw();
      this_thread::sleep_for(200ms);
    }
  }

  void syncData(shared_ptr<Sync> sync) {
    sync->sync();
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
    shared_ptr<vector<shared_ptr<Char>>> characters (new vector<shared_ptr<Char>>({}));
    
    // Server
    shared_ptr<Sync> sync (new Sync(map, characters));
    thread sync_data (syncData, sync);

    // Main Loop
    mainLoop(map, characters, sync);

    return 0;
  }
