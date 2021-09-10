#include "view.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

using namespace std;

View::View(shared_ptr<Model> bg, shared_ptr<Model> fg) : bg(bg), fg(fg) {

// Criando uma janela
    window = nullptr;
    window = SDL_CreateWindow("Demonstracao do SDL2",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN);
    if (window==nullptr) { // Em caso de erro...
        cout << SDL_GetError();
        SDL_Quit();
    }

            // Inicializando o renderizador
    renderer = SDL_CreateRenderer(
    window, -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer==nullptr) { // Em caso de erro...
        SDL_DestroyWindow(window);
        cout << SDL_GetError();
        SDL_Quit();
    }

    bg->setTexture(this->render(bg));
    fg->setTexture(this->render(fg));
}

View::~View() {
     SDL_DestroyTexture(bg->getTexture());
     SDL_DestroyTexture(fg->getTexture());
     SDL_DestroyRenderer(renderer);
     SDL_DestroyWindow(window);
     SDL_Quit();
 }

SDL_Texture*View:: render(shared_ptr<Model> model) {
	SDL_Texture *texture = IMG_LoadTexture(renderer, model->getFile());
        SDL_QueryTexture(texture, nullptr, nullptr, model->getW(), model->getH());
        return texture;
 }

void View::draw() {
        // Desenhar a cena
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, bg->getTexture(), nullptr, nullptr);
        SDL_RenderCopy(renderer, fg->getTexture(), nullptr, fg->getTarget());
        SDL_RenderPresent(renderer);
        // Delay para diminuir o framerate
	SDL_Delay(10);
 }
