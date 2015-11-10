//
//  SquareTest.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef SquareTest_h
#define SquareTest_h

#include "gtest/gtest.h"
#include "Square.h"
#include "Piece.h"

using testing::Test;
using UPoint = Point<unsigned>;

class SquareTest: public Test {
};

TEST_F(SquareTest, DefaultConstructor) {
  Square *s = new Square();
  EXPECT_EQ(colors::red, s->getColor());
  EXPECT_EQ(0, s->getPosition().getX());
  EXPECT_EQ(0, s->getPosition().getY());
}

TEST_F(SquareTest, SimpleInitRed) {
  Square *s = new Square(colors::red, UPoint(10, 20));
  EXPECT_EQ(colors::red, s->getColor());
  EXPECT_EQ(10, s->getPosition().getX());
  EXPECT_EQ(20, s->getPosition().getY());
}

TEST_F(SquareTest, SimpleInitBlack) {
  Square *s = new Square(colors::black, UPoint(10, 20));
  EXPECT_EQ(colors::black, s->getColor());
  EXPECT_EQ(10, s->getPosition().getX());
  EXPECT_EQ(20, s->getPosition().getY());
}

TEST_F(SquareTest, InitWithNoPiece) {
  Square s(colors::black, UPoint(10, 20));
  EXPECT_EQ(false, s.hasPiece());
  EXPECT_EQ(nullptr, s.getPiece());

  Square s1(colors::black, UPoint(10, 20), nullptr);
  EXPECT_EQ(false, s1.hasPiece());
  EXPECT_EQ(nullptr, s1.getPiece());
}


TEST_F(SquareTest, InitWithPiece) {
  Square s(colors::black, UPoint(10, 20), new Piece);
  EXPECT_EQ(true, s.hasPiece());
  EXPECT_NE(nullptr, s.getPiece());
}

#endif /* SquareTest_h */
