#ifndef COORD_H
#define COORD_H

using namespace std;

class Coord {
    private:
        int x;
        int y;

    public:
        Coord(int x, int y);
        
        int getX();
        int getY();

        void setX(int x);
        void setY(int y);
};

#endif
