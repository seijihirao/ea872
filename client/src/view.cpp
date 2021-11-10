#include "../include/view.h"

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 440;

using namespace std;

View::View(shared_ptr<Map> map, shared_ptr<Char> character) : map(map), character(character){
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

    this->map->setTexture(this->render(map));
    this->character->setTexture(this->render(character));

    for(int i = 0; i < this->map->getBricks().size(); i++)
      this->map->getBricks()[i]->setTexture(this->render(this->map->getBricks()[i]));

    for(int i = 0; i < this->map->getBlocks().size(); i++)
      this->map->getBlocks()[i]->setTexture(this->render(this->map->getBlocks()[i]));
}

View::~View() {
    int i;

    for(i = 0; i < this->map->getBricks().size(); i++) {
    	SDL_DestroyTexture(this->map->getBricks()[i]->getTexture());
    }

    for(i = 0; i < this->map->getBlocks().size(); i++) {
      SDL_DestroyTexture(this->map->getBlocks()[i]->getTexture());
    }

    for(i = 0; i < this->bombs.size(); i++) {
      SDL_DestroyTexture(this->bombs[i]->getTexture());
    }

     SDL_DestroyTexture(character->getTexture());

     SDL_DestroyTexture(map->getTexture());
     SDL_DestroyRenderer(renderer);
     SDL_DestroyWindow(window);
     SDL_Quit();
}

SDL_Texture*View:: render(shared_ptr<Texture> texture_ext) {
	SDL_Texture *texture = IMG_LoadTexture(renderer, texture_ext->getFile());
        SDL_QueryTexture(texture, nullptr, nullptr, texture_ext->getWidth(), texture_ext->getHeight());
        return texture;
}

void View::renderBomb(shared_ptr<Bomb> bomb) {
    bomb->setTexture(this->render(bomb));
    this->bombs.push_back(bomb);
}

void View::draw() {
    int i;

    // Desenhar a cena
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, this->map->getTexture(), nullptr, nullptr);

    for(i = 0; i < this->map->getBricks().size(); i++) {
    	SDL_RenderCopy(renderer, this->map->getBricks()[i]->getTexture(), nullptr, this->map->getBricks()[i]->getTarget());
    }

    for(i = 0; i < this->map->getBlocks().size(); i++) {
      	SDL_RenderCopy(renderer, this->map->getBlocks()[i]->getTexture(), nullptr, this->map->getBlocks()[i]->getTarget());
    }

    SDL_RenderCopy(renderer, this->character->getTexture(), nullptr, this->character->getTarget());

    for(i = 0; i < this->bombs.size(); i++) {
        SDL_RenderCopy(renderer, bombs[i]->getTexture(), nullptr, bombs[i]->getTarget());
    }


    SDL_RenderPresent(renderer);
    // Delay para diminuir o framerate
    SDL_Delay(10);
 }
