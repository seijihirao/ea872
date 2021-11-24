#include "../../include/controllers/sync.h"
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "../../../ext/json.hpp"

using namespace std;
using boost::asio::ip::udp;

Sync::Sync(shared_ptr<Map> map, vector<Char> characters) : map(map), characters(characters) {
}

void Sync::sync() {
    boost::asio::io_service io_service;
    
    udp::endpoint local_ep (udp::v4(), 9001);
    udp::socket sync_socket (io_service, local_ep);

    udp::endpoint remote_ep;
    
    cout << "Server started" << endl;

    while(true) {
        char input[4096];
        memset(input, 0, 4096); 
        sync_socket.receive_from(boost::asio::buffer(input, 4096), remote_ep);

        string request = input;
        cout << "Request: " << request << endl;

        auto data = json::parse(request);
        json response;
        int player_number = data["player"];
        if (data["player"] == -1) {
            player_number = this->_createNewPlayer();
        } else {
            Coord position = data["characters"][player_number]["position"];
            this->characters[player_number].setPosition(position);
            if (!data["alive"]) {
                this->characters[player_number].kill();
            }
        }
        
        response["player"] = player_number;
        response["characters"] = this->characters;
        cout << "Response: " << response.dump() << endl;
        sync_socket.send_to(boost::asio::buffer(response.dump()), remote_ep);
    }
}

int Sync::_createNewPlayer() {
    int player_number = this->characters.size();
    Coord position = Coord(0, 0);
    Char character(position);
    
    this->characters.push_back(character);

    cout << "Assigned player " << player_number << endl;
    
    return player_number;
}
