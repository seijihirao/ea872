#ifndef SYNC_H
#define SYNC_H

#include "../../../shared/include/models/map.h"
#include "../../../shared/include/models/char.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using boost::asio::ip::udp;

class Sync {
    private:
        /** Character pointer */
        vector<Char> characters;

        /** Map pointer*/
        const shared_ptr<Map> map;

    public:
        /**
         * Creates a service to sync data with clients via UDP
         *
         * @param map - map in which character will walk
         * @param character - character to move
         */
        Sync(shared_ptr<Map> map, vector<Char> characters);

        /**
         * Synchronizes data with client
         */
        void sync();

        /**
         * Creates new player
         *
         * @returns player number
         */
        int _createNewPlayer();

};

#endif
