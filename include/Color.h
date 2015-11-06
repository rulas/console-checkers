//
//  Color.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef Color_h
#define Color_h

#include <string>
#include <vector>

using std::string;
using std::vector;

enum class colors {
    none = 0, red, black
};

class ColorStr {
 public:
    static string toString(colors color){
        if (color == colors::red) {
            return "red";
        } else if (color == colors::black) {
            return "black";
        }

        return "none";
    }
};

#endif /* Color_h */
