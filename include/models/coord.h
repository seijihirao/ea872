#ifndef COORD_H
#define COORD_H

using namespace std;

class Coord {
    private:
        /** horizontal position */
        int x;

        /** vertical position */
        int y;

    public:
        /**
         * Coordinate object, basically a pair of integers
         *
         * @param x - position x
         * @param y - position y
         */
        Coord(int x, int y);
        
        /**
         * Gets current x position
         *
         * @returns horizontal position
         */
        int getX();
        
        /**
         * Gets current y position
         *
         * @returns vertical position
         */
        int getY();
        
        /**
         * Sets current x position
         *
         * @param x - horizontal position
         */
        void setX(int x);
        
        /**
         * Sets current y position
         *
         * @param y - vertical position
         */
        void setY(int y);
};

#endif
