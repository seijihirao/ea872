#include "controller.h"

using namespace std;

FGController::FGController(shared_ptr<Model> fg) : fg(fg) {
    state = SDL_GetKeyboardState(nullptr); // estado do teclado
}

void FGController::move() {
    SDL_PumpEvents(); // atualiza estado do teclado
    if (state[SDL_SCANCODE_LEFT]) fg->moveLeft();
    if (state[SDL_SCANCODE_RIGHT]) fg->moveRight();
    if (state[SDL_SCANCODE_UP]) fg->moveUp();
    if (state[SDL_SCANCODE_DOWN]) fg->moveDown();
}
