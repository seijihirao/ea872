#include "../include/view.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

using namespace std;

View::View(shared_ptr<Map> map) : map(map){
    // Criando uma janela
    window = nullptr;
    window = SDL_CreateWindow("EA872",
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

    map->setTexture(this->render(map));
}

View::~View() {
     SDL_DestroyTexture(map->getTexture());
     SDL_DestroyRenderer(renderer);
     SDL_DestroyWindow(window);
     SDL_Quit();
}

void View::addChar(shared_ptr<Char> character) {
    character->setTexture(this->render(map));
}

SDL_Texture*View:: render(shared_ptr<Map> map) {
	int a,b;
	a = map->getWidth();
	b = map->getHeight();


	SDL_Texture *texture = IMG_LoadTexture(renderer, map->getFile());
        SDL_QueryTexture(texture, nullptr, nullptr, &a, &b);
        return texture;
}

void View::listenMovement(shared_ptr<Movement> movement) {
    movement->move();
    SDL_RenderCopy(renderer, movement->getChar()->getTexture(), nullptr, movement->getChar()->getTarget());
}


void View::draw() {
    // Desenhar a cena
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, this->map->getTexture(), nullptr, nullptr);
    SDL_RenderPresent(renderer);
    // Delay para diminuir o framerate
    SDL_Delay(10);
 }
