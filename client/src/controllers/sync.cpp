#include "../../include/controllers/sync.h"
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using boost::asio::ip::udp;

Sync::Sync(shared_ptr<Map> map, shared_ptr<Char> character) : map(map), character(character) {
    boost::asio::io_service io_service;
    
    udp::endpoint local_ep(udp::v4(), 0);
    udp::socket skt(io_service, local_ep);
    this->skt = skt;

    boost::asio::ip:address remote_ip = boost::asio::ip::address::from_string("127.0.0.1");

    udp::endpoint remote_ep(remote_ip, 9001);
    this->remote_ep = remote_ep;
}

void Sync:sync() {
    string msg("Test Test Test");
    this->skt.send_to(boost::asio::buffer(msg), this->remote_ep);
    this->skt.receive_from(boost::asio::buffer(msg, 122), this->remote_ep);
    cout << msg << endl;
}
