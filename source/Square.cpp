//
// Created by Raul Villanueva on 11/6/15.
//

#include <sstream>
#include <string>
#include "Square.h"

using std::stringstream;

Square::Square() {
  position = UPoint(0, 0);
  color = colors::red;
  piece = nullptr;
}

Square::Square(colors newcolor, UPoint newpos) {
  position = newpos;
  color = newcolor;
  piece = nullptr;
}

Square::Square(colors newcolor, UPoint newpos, Piece *newpiece) {
  position = newpos;
  color = newcolor;
  piece = newpiece;
}

Square::~Square() {
}

UPoint Square::getPosition() {
  return position;
}

void Square::setPosition(UPoint newpos) {
  position = newpos;
}

colors Square::getColor() {
  return color;
}

void Square::setColor(colors newcolor) {
  color = newcolor;
}

string Square::toString() {
  stringstream ss;

  ss << "Square <" << ColorStr::toString(color)
      << ", " << position.toString() << ">";

  return ss.str();
}

void Square::setPiece(Piece *newpiece) {
  piece = newpiece;
}

Piece *Square::getPiece() {
  return piece;
}

bool Square::hasPiece() {
  return piece != nullptr;
}
