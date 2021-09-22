#ifndef COORD_H
#define COORD_H

using namespace std;

class Coord {
    private:
        int x;
        int y;

    public:
        Map(int x, int y);
        
        int getX();
        int getY();

        int setX();
        int setY();
};

#endif
