//
//  Piece.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef Piece_h
#define Piece_h

#include <vector>
#include <string>
#include "Point.h"
#include "Color.h"


using std::vector;
using std::string;

class Piece {
 public:
    Piece() {
        position = Point(0, 0);
        color = colors::red;
        king = false;
    }

    Piece(colors newcolor, Point newpos) {
        position = newpos;
        color = newcolor;
        king = false;
    }

    Piece(colors newcolor, int newx, int newy) {
        position = Point(newx, newy);
        color = newcolor;
        king = false;
    }

    void setPosition(Point newpos) {
        position = newpos;
    }

    Point getPosition() {
        return position;
    }

    void setColor(colors newcolor) {
        color = newcolor;
    }

    colors getColor() {
        return color;
    }

    void makeKing() {
        king = true;
    }

    bool isKing() {
        return king;
    }

    void move(Point newpos) {
        //
    }

 private:
    Point position;
    colors color;
    bool king;
};
#endif /* Piece_h */
