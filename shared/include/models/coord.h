#pragma once

#include "../../../ext/json.hpp"

using namespace std;
using nlohmann::json;

class Coord {
    private:
        /** horizontal position */
        int x;

        /** vertical position */
        int y;

    public:
      	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Coord, x, y);

        /**
         * Coordinate object, basically a pair of integers
         */
        Coord();

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
