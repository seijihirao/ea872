#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/models/char.h"
#include "../include/models/coord.h"
#include "../include/models/map.h"
#include "../include/models/texture.h"
#include "../include/view.h"
#include "../include/controllers/movement.h"


using namespace std;

int main() {

    // Inicializando o subsistema de video do SDL
    if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
        return 1;
    }

    // MVC
    Coord position = Coord(1,1);
    shared_ptr<Map> map (new Map("../assets/bg.jpeg", 0, 0));
    shared_ptr<View> view (new View(map));
    shared_ptr<Char> character (new Char("../assets/player.png", position));
    view->addChar(character);
 
    shared_ptr<Movement> movement (new Movement(map, character));

    // Error handling

    bool run = true;

    SDL_Event event; // eventos discretos

    // Main loop
    while(run) {
        view->listenMovement(movement);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                run = false;
            }
        }

        view->draw();
    }

    return 0;
}
