#include "../../include/controllers/sync.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <thread>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "../../../ext/json.hpp"

using namespace std;
using boost::asio::ip::udp;

Sync::Sync(shared_ptr<Map> map, shared_ptr<vector<shared_ptr<Char>>> characters) : map(map), characters(characters) {
}

void Sync::sync() {
  boost::asio::io_service io_service;

  udp::endpoint local_ep(udp::v4(), 0);
  udp::socket sync_socket(io_service, local_ep);

  boost::asio::ip::address remote_ip = boost::asio::ip::address::from_string("127.0.0.1");

  udp::endpoint remote_ep (remote_ip, 9001);

  while (true) {
    json request;
    request["player"] = this->player_number;
    vector<Char> characters = {};
    for (shared_ptr<Char> character : *this->characters) {
      characters.push_back(*character);
    }
    request["characters"] = characters;

    string request_data = request.dump();
    cout << "Request: " << request_data << endl;
    sync_socket.send_to(boost::asio::buffer(request_data.c_str(), request_data.length()), remote_ep);

    char response[4096];
    memset(response, 0, 4096);
    sync_socket.receive_from(boost::asio::buffer(response, 4096), remote_ep);

    cout << "Response: " << response << endl;

    auto response_data = json::parse(response);
    this->player_number = response_data["player"];
    for (int i = 0; i < response_data["characters"].size(); i++) {
      Coord position = response_data["characters"][i]["position"];
      if (i >= this->characters->size()) {
        shared_ptr<Char> new_character (new Char(position));
        this->characters->push_back(new_character);
      }
      (*this->characters)[i]->setPosition(position);

      bool isAlive = response_data["characters"][i]["alive"];
      if (!isAlive) {
        (*this->characters)[i]->kill();
      }
    }
    this_thread::sleep_for(100ms);
  }
}


int Sync::getPlayerNumber() {
  return this->player_number;
}

bool Sync::hasPlayerNumber() {
  return this->getPlayerNumber() != -1;
}
