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
using UPoint = Point<unsigned>;

class Piece {
 public:
  Piece();
  Piece(colors newcolor);
  Piece(colors newcolor, UPoint newpos);
  Piece(colors newcolor, unsigned newx, unsigned newy);

  void setPosition(UPoint newpos);
  UPoint getPosition();
  void setColor(colors newcolor);
  colors getColor();
  void makeKing();
  bool isKing();
  void move(UPoint newpos);

 private:
  UPoint position;
  colors color;
  bool king;
};
#endif /* Piece_h */
