#include "../include/controllers/sync.h"
#include "../../shared/include/models/map.h"
#include "../../shared/include/models/char.h"
#include <thread>

using namespace std;

void syncData(shared_ptr<Sync> sync) {
    sync->sync();
}

int main() {

    shared_ptr<Map> map (new Map("", 0, 0));
    vector<Char> characters = {};

    shared_ptr<Sync> sync (new Sync(map, characters));
    
    syncData(sync);
    
    return 0; 
}
