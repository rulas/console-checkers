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
  TerminalSprite();
  void clear();
  void clear(char newchar);
  void renderLine(char newchar, int startrow, int startcol, int endrow,
                  int endcol);
  void renderPoint(char newchar, int row, int col);
  void renderHLine(char newchar, int startrow, int startcol, int lenght);
  void renderVLine(char newchar, int startrow, int startcol, int lenght);
  void renderSquare(char newchar, int startrow, int startcol, int endrow,
                    int endcol);
  void draw();
  string toString();
 private:
  bool validRow(int row);
  bool validCol(int col);

 private:
  char matrix[rows][cols];
};


#endif /* TerminalSprite_h */
