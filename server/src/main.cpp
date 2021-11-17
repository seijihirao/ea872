#include "../include/controllers/sync.h"
#include "../../shared/include/models/map.h"
#include "../../shared/include/models/char.h"

using namespace std;

int main() {

    shared_ptr<Map> map (new Map("", 0, 0));
    map->_populate("", "");
    
    vector<Char> characters = {};

    Sync sync = Sync(map, characters);
    sync.sync();
    return 0; 
}
