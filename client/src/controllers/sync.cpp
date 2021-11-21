#include "../../include/controllers/sync.h"
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using boost::asio::ip::udp;

Sync::Sync(shared_ptr<Map> map, shared_ptr<Char> character) : map(map), character(character) {
}

void Sync::sync() {
    boost::asio::io_service io_service;
    
    udp::endpoint local_ep(udp::v4(), 0);
    udp::socket sync_socket(io_service, local_ep);

    boost::asio::ip::address remote_ip = boost::asio::ip::address::from_string("127.0.0.1");

    udp::endpoint remote_ep (remote_ip, 9001);

    string msg("{\"player\": 0}");
    sync_socket.send_to(boost::asio::buffer(msg), remote_ep);
    
    char response[120];
    sync_socket.receive_from(boost::asio::buffer(response, 120), remote_ep);
    cout << response << endl;
}
