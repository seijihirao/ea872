#include "../../include/controllers/sync.h"
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using boost::asio::ip::udp;

Sync::Sync(shared_ptr<Map> map, vector<Char> characters) : map(map), characters(characters) {
    boost::asio::io_service io_service;
    
    udp::endpoint local_ep(udp::v4(), 9001);
    udp::socket sync_socket(io_service, local_ep);

    udp::endpoint remote_ep;
    
    this->sync_socket = &sync_socket;
    this->remote_ep = &remote_ep; 
}

void Sync::sync() {
    char msg[120];
    (*this->sync_socket).receive_from(boost::asio::buffer(msg, 120), *this->remote_ep);
    cout << msg << endl;
    (*this->sync_socket).send_to(boost::asio::buffer(msg), *this->remote_ep);
}
