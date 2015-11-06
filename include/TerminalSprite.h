//
//  TerminalSprite.h
//  Checkers
//
//  Created by Raul Villanueva on 11/5/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef TerminalSprite_h
#define TerminalSprite_h


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <cstdint>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

const int rows = 40;
const int cols = 80;


class TerminalSprite {
 public:
    TerminalSprite() {
        clear();
    }

    void clear();
    void clear(uint8_t newchar);
    void renderLine(uint8_t newchar, int startrow, int startcol, int endrow,
                    int endcol);
    void renderPoint(uint8_t newchar, int row, int col);
    void renderHLine(uint8_t newchar, int startrow, int startcol, int lenght);
    void renderVLine(uint8_t newchar, int startrow, int startcol, int lenght);
    void renderSquare(uint8_t newchar, int startrow, int startcol, int endrow,
                      int endcol);
    void draw();
    string toString();
 private:
    bool validRow(int row);
    bool validCol(int col);

 private:
    uint8_t matrix[rows][cols];
};




#endif /* TerminalSprite_h */
