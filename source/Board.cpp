//
// Created by Raul Villanueva on 11/6/15.
//

#include <string>
#include <vector>
#include "Board.h"

using std::string;
using std::vector;

Board::Board() {
  height = kRows;
  width = kCols;
  Init();
}

void Board::Init() {
  // creates neccesary squares
  for (unsigned y = 0; y < height; y++) {
    vector<Square> row;
    for (unsigned x = 0; x < width; x++) {
      if ((y % 2) ^ (x % 2)) {
        // row 3 and four has no pieces
        if (y < 3) {
          row.push_back(Square(colors::black, UPoint(x, y), new Piece(colors::black)));
        } else if (y >= 5 && y < 8) {
          row.push_back(Square(colors::black, UPoint(x, y), new Piece(colors::white)));
        } else {
          row.push_back(Square(colors::black, UPoint(x, y), nullptr));
        }
      } else {
        row.push_back(Square(colors::red, UPoint(x, y)));
      }
    }
    squares.push_back(row);
  }
}

void Board::Setup() {
}

void Board::Draw() {
  for (unsigned y = 0; y < squares.size(); y++) {
    for (unsigned x = 0; x < squares[y].size(); x++) {
      Square *s = &squares[y][x];
      if (s->getColor() == colors::red) {
        cout << " ";
      } else {
        cout << "#";
      }
    }
    cout << endl;
  }
}

string Board::pointToCoord(UPoint point) {
  char xcoord;
  char ycoord;
  string coord;

  xcoord = 'A' + static_cast<char>(point.getX());
  ycoord = '0' + static_cast<char>(point.getY());

  coord += xcoord;
  coord += ycoord;

  return coord;
}

UPoint Board::coordToPoint(string coord) {
  char xcoord = static_cast<char>(toupper(coord[0]));
  char ycoord = coord[1];
  // "A" = 0, "B" = 1, "C" = 2, "D" = 3, ...
  // 0 = 7, 1 = 6, 2 = 5, 3 = 4, ..
  unsigned xpoint = unsigned(xcoord - 'A');
  unsigned ypoint = unsigned(abs(ycoord - '0' - 7));

  return UPoint(xpoint, ypoint);
}

vector<vector<Square>> &Board::getSquares() {
  return squares;
}

vector<vector<Piece>> &Board::getPieces() {
  return pieces;
}

Piece *Board::getPieceAt(UPoint p) {
  return squares[p.getY()][p.getX()].getPiece();
}

Square &Board::getSquareAt(UPoint p) {
  return squares[p.getY()][p.getX()];
}