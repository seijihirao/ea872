#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/models/char.h"
#include "../include/models/coord.h"
#include "../include/models/map.h"
#include "../include/models/texture.h"
#include "../include/models/brick.h"
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
    Coord position = Coord(0,0);
    shared_ptr<Map> map (new Map("../assets/bg.jpg", 680, 440));
    shared_ptr<Char> character (new Char("../assets/player.png", position, 40, 40));
    shared_ptr<View> view (new View(map, character));
    shared_ptr<Movement> movement (new Movement(map, character));
    
    view->construct("../assets/brick.png");

    // Error handling

    bool run = true;

    SDL_Event event; // eventos discretos

    // Main loop
    while(run) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                run = false;
            }
        }
        
	movement->move(event);

        view->draw();
    }

    return 0;
}
