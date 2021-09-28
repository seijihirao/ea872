#include "../../include/models/coord.h"

using namespace std;

Coord::Coord(int x, int y) : 
    x(x), 
    y(y) {
}

int Coord::getX() {
    return this.x;
}

int Coord::getY() {
    return this.y;
}

void Coord::setX(int x) {
    this.x = x;
}

void Coord::setY(int y) {
    this.y = y;
}
