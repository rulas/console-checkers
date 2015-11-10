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
#include "Piece.h"

using std::string;
using std::vector;

using UPoint = Point<unsigned>;

class Square {
 public:
  Square();
  Square(colors newcolor, UPoint newpos);
  Square(colors newcolor, UPoint newpos, Piece *piece);
  ~Square();
  UPoint getPosition();
  void setPosition(UPoint newpos);
  colors getColor();
  void setColor(colors newcolor);
  void setPiece(Piece *newpiece);
  Piece *getPiece();
  bool hasPiece();
  string toString();

 private:
  UPoint position;
  colors color;
  Piece *piece;
};


#endif /* Square_h */
