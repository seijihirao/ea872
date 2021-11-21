#include "../../include/controllers/sync.h"
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "../../../ext/json.hpp"

using namespace std;
using boost::asio::ip::udp;

Sync::Sync(shared_ptr<Map> map, vector<Char> characters) : map(map), characters(characters) {
    cout << "Server started" << endl;
}

void Sync::sync() {
    boost::asio::io_service io_service;
    
    udp::endpoint local_ep (udp::v4(), 9001);
    udp::socket sync_socket (io_service, local_ep);

    udp::endpoint remote_ep;

    while(true) {
        char input[120];
        sync_socket.receive_from(boost::asio::buffer(input, 120), remote_ep);
        auto data = json::parse(input);
        if (data["player"] == -1) {
            this->_createNewPlayer();

            string response("Success");
            sync_socket.send_to(boost::asio::buffer(response), remote_ep);
        } else {
            cout << data["player"] << endl;
        }
    }
}

int Sync::_createNewPlayer() {
    int player_number = this->characters.size() - 1;

    cout << "Assigned player " << player_number << endl;
    
    return player_number;
}
