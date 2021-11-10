#pragma once

#include "../../../shared/include/models/map.h"
#include "../../../shared/include/models/char.h"

using namespace std;

class Save {
    private:
        /** Character pointer */
        const shared_ptr<Char> character;

        /** Map pointer */
        const shared_ptr<Map> map;

    public:
        /**
         * Creates a service to manage save on a json file
         *
         * @param map - map in which character will walk
         * @param character - character to move
         */
        Save(shared_ptr<Map> map, shared_ptr<Char> character);
        
        /**
         * Saves game status to json
         */
        void save();
        
	/**
	 * Gets character data from json and sets internal variables
	 */
	void load();

	/**
	 * Gets current character
	 */
	shared_ptr<Char> getChar();
};
