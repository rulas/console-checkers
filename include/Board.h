//
//  Board.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef CheckersBoard_h
#define CheckersBoard_h

#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <string>
#include "Square.h"
#include "Piece.h"
#include "Point.h"
#include "TerminalSprite.h"

using std::cout;
using std::endl;
using std::vector;
using std::stoi;
using UPoint = Point<unsigned>;

const int kCols = 8;
const int kRows = 8;

struct Position {
  int x;
  int y;
};

class Board {

 public:
  Board();
  void Init();
  void Setup();
  void Draw();
  vector<vector<Square>> &getSquares();
  vector<vector<Piece>> &getPieces();
  string pointToCoord(UPoint point);
  UPoint coordToPoint(string coord);
  Square &getSquareAt(UPoint p);
  Piece *getPieceAt(UPoint p);

 private:
  unsigned height;
  unsigned width;
  vector<vector<Square>> squares;
  vector<vector<Piece>> pieces;
};


#endif /* CheckersBoard_h */
