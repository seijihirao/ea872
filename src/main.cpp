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
    shared_ptr<Model> bg (new Model("../assets/park.jpeg", 0, 0));
    shared_ptr<Model> fg (new Model("../assets/capi.png", 0, 0));
    shared_ptr<FGController> fg_controller (new FGController(fg));
    shared_ptr<View> view (new View(bg, fg));

    // Error handling

    bool run = true;

    SDL_Event evento; // eventos discretos

    // Main loop
    while(run) {
        fg_controller->move();

        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                run = false;
            }
        }

        view->draw();
    }

    return 0;
}
