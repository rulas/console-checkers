//
//  Point.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef Point_h
#define Point_h

#include <sstream>
#include <string>

using std::string;
using std::stringstream;

class Point {
 private:
    int x;
    int y;

 public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int newx, int newy) {
        x = newx;
        y = newy;
    }

    void setX(int newx) {
        x = newx;
    }

    int getX() {
        return x;
    }

    void setY(int newy) {
        y = newy;
    }

    int getY() {
        return y;
    }

    string toString() {
        stringstream ss;
        ss << "Point<" << getX() << ", " << getY() << ">";
        return ss.str();
    }
};

#endif /* Point_h */
