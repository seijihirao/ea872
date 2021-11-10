#include "../../include/controllers/sync.h"
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using boost::asio::ip::udp;

Sync::Sync(shared_ptr<Map> map, vector<Char> characters) : map(map), characters(characters) {
}

void Sync::sync() {
    boost::asio::io_service io_service;
    
    udp::endpoint local_ep(udp::v4(), 9001);
    udp::socket skt(io_service, local_ep);

    udp::endpoint remote_ep;

    char msg[120];
    skt.receive_from(boost::asio::buffer(msg, 120), remote_ep);
    cout << msg << endl;
    skt.send_to(boost::asio::buffer(msg), remote_ep);
}
