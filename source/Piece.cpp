//
// Created by Raul Villanueva on 11/6/15.
//

#include "Piece.h"


Piece::Piece() {
  position = UPoint(0, 0);
  color = colors::red;
  king = false;
}

Piece::Piece(colors newcolor) {
  position = UPoint(0, 0);
  color = newcolor;
  king = false;
}

Piece::Piece(colors newcolor, UPoint newpos) {
  position = newpos;
  color = newcolor;
  king = false;
}

Piece::Piece(colors newcolor, unsigned newx, unsigned newy) {
  position = UPoint(newx, newy);
  color = newcolor;
  king = false;
}

void Piece::setPosition(UPoint newpos) {
  position = newpos;
}

UPoint Piece::getPosition() {
  return position;
}

void Piece::setColor(colors newcolor) {
  color = newcolor;
}

colors Piece::getColor() {
  return color;
}

void Piece::makeKing() {
  king = true;
}

bool Piece::isKing() {
  return king;
}

void Piece::move(UPoint newpos) {
  //
  newpos = newpos;
}
