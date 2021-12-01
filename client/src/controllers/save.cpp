#include "../../include/controllers/save.h"
#include "../../../ext/json.hpp"
#include <fstream>

using namespace std;
using nlohmann::json;

Save::Save(shared_ptr<Map> map, shared_ptr<Char> character) : map(map), character(character) {
}

void Save::save() {
	json j;
	j["character"] = *this->character;

	ofstream file;
	file.open("save.json");
	file << j;
	file.close();
}

void Save::load() {
	json j;
	ifstream file;
	file.open("save.json");
	file >> j;
	file.close();

	this->character->setPosition(j["character"]["position"]);
}

shared_ptr<Char> Save::getChar() {
	return this->character;
}
