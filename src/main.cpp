#include "model.h"
#include "view.h"
#include "controller.h"

using namespace std;

int main() {
    // Inicializando o subsistema de video do SDL
    if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
        return 1;
    }

    // MVC
    shared_ptr<Map> map (new Model("../assets/park.jpeg", 0, 0));
    shared_ptr<View> view (new View(map));
    
    shared_ptr<Char> character (new Model("../assets/capi.png", 0, 0));
    map->addChar(character);
 
    shared_ptr<Movement> movement (new Movement(this.map, character));

    // Error handling

    bool run = true;

    SDL_Event event; // eventos discretos

    // Main loop
    while(run) {
        view->listenMovement(character);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                run = false;
            }
        }

        view->draw();
    }

    return 0;
}
