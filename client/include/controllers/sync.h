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
  shared_ptr<vector<shared_ptr<Char>>> characters;

  /** Map pointer*/
  const shared_ptr<Map> map;

  /** player number*/
  int player_number = -1;

public:
  /**
  * Creates a service to sync data with the server via UDP
  *
  * @param map - map in which character will walk
  * @param character - character to move
  */
  Sync(shared_ptr<Map> map, shared_ptr<vector<shared_ptr<Char>>> characters);

  /**
  * Synchronizes data with server
  */
  void sync();

  /**
  * Gets current player number
  *
  * @returns player number or -1 if no number assigned
  */
  int getPlayerNumber();

  /**
  * Gets if player has number
  *
  * @returns player number != -1
  */
  bool hasPlayerNumber();

};
