//
//  Square.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef Square_h
#define Square_h

#include <sstream>
#include <string>
#include <vector>
#include "Point.h"
#include "Color.h"

using std::stringstream;
using std::string;
using std::vector;

class Square {
 private:
    Point position;
    colors color;

 public:
    Square() {
        position = Point(0, 0);
        color = colors::red;
    }

    Square(colors newcolor, Point newpos) {
        position = newpos;
        color = newcolor;
    }

    Point getPosition() {
        return position;
    }

    void setPosition(Point newpos) {
        position = newpos;
    }

    colors getColor() {
        return color;
    }

    void setColor(colors newcolor) {
        color = newcolor;
    }

    string toString() {
        stringstream ss;

        ss << "Square <" << ColorStr::toString(color)
            << ", " << position.toString() << ">";

        return ss.str();
    }
};


#endif /* Square_h */
