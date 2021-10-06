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
}

View::~View() {

    for(int i = 0; i < this->bricks.size(); i++)
    	SDL_DestroyTexture(this->bricks[i]->getTexture());

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

void View::construct(string url){
	
	for (int i = 1; i < this->map->getMaxX(); i += 2) {
        	for(int j = 1; j < this->map->getMaxY(); j += 2) {
            	bricks.push_back(shared_ptr<Brick>(new Brick(url,40*i,40*j)));
        }
    }
    
	for(int i = 0; i < bricks.size(); i++)
	   this->bricks[i]->setTexture(this->render(bricks[i]));

}

void View::draw() {
    
    // Desenhar a cena
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, this->map->getTexture(), nullptr, nullptr);
    
    for(int i = 0; i < this->bricks.size(); i++)
    	SDL_RenderCopy(renderer, this->bricks[i]->getTexture(), nullptr, this->bricks[i]->getTarget());
    
    SDL_RenderCopy(renderer, this->character->getTexture(), nullptr, this->character->getTarget());
    SDL_RenderPresent(renderer);
    // Delay para diminuir o framerate
    SDL_Delay(10);
 }
