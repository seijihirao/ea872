#pragma once

#include <memory>
#include "../../../shared/include/models/map.h"
#include "../../../shared/include/models/char.h"
#include "../../../shared/include/models/bomb.h"

using namespace std;

class BombControl {
    private:
        /** Character pointer */
        const shared_ptr<Char> character;

        /** Map pointer */
        const shared_ptr<Map> map;

    public:
        /**
         * Creates a service to manage bombs
         *
         * @param map - map in which character will walk
         * @param character - character to move
         */
        BombControl(shared_ptr<Map> map, shared_ptr<Char> character);

        /**
         * Creates bomb deppending on key event
         *
         * @param event - keyboard event
         */
        shared_ptr<Bomb> listen(SDL_Event event);

        /**
         * Creates bomb on current character position
         * with explosion callback
         *
         * @returns Newly created bomb
         */
        shared_ptr<Bomb> createNewBomb();
};
