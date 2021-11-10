#pragma once

#include "../../../shared/include/models/map.h"
#include "../../../shared/include/models/char.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using boost::asio::ip::udp;

class Sync {
    private:
        /** Character pointer */
        const shared_ptr<Char> character;

        /** Map pointer*/
        const shared_ptr<Map> map;

        /** UDP socket */
        udp::socket skt;

        /** Remote endpoint */
        udp::endpoint remote_ep;

    public:
        /**
         * Creates a service to sync data with the server via UDP
         *
         * @param map - map in which character will walk
         * @param character - character to move
         */
        Sync(shared_ptr<Map> map, shared_ptr<Char> character);

        /**
         * Synchronizes data with server
         */
        void sync();

};