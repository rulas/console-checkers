//
//  PieceTest.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef PieceTest_h
#define PieceTest_h

#include "gtest/gtest.h"
#include "Piece.h"

using testing::Test;
using UPoint = Point<unsigned>;

class PieceTest: public Test {
};

TEST_F(PieceTest, ConstructorTest) {
  Piece *p;
  p = new Piece;

  EXPECT_EQ(colors::red, p->getColor());
  EXPECT_EQ(0, p->getPosition().getX());
  EXPECT_EQ(0, p->getPosition().getY());
}

TEST_F(PieceTest, MakeRedPiece) {
  Piece *p;
  p = new Piece(colors::red, UPoint(8, 8));
  EXPECT_EQ(colors::red, p->getColor());
  EXPECT_EQ(8, p->getPosition().getX());
  EXPECT_EQ(8, p->getPosition().getY());
}

TEST_F(PieceTest, MakeBlackPiece) {
  Piece *p;
  p = new Piece(colors::black, UPoint(8, 8));
  EXPECT_EQ(colors::black, p->getColor());
  EXPECT_EQ(8, p->getPosition().getX());
  EXPECT_EQ(8, p->getPosition().getY());
}


#endif /* PieceTest_h */
