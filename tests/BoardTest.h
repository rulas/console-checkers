//
//  BoardTest.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef BoardTest_h
#define BoardTest_h

#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "Board.h"
#include "Color.h"


using testing::Test;
using std::string;
using std::cout;
using std::endl;
using UPoint = Point<unsigned>;

class BoardTest: public Test {
};

TEST_F(BoardTest, BoardSetup) {
  Board board;
  int num = 0;
  int reds = 0;
  int blacks = 0;
//    auto squares = m_board.getSquares();
  for (auto square_row : board.getSquares()) {
    for (auto square : square_row) {
      num++;
//            cout << "position: " << square.toString() << endl;
      if (square.getColor() == colors::red) {
        reds++;
      } else {
        blacks++;
      }
    }
  }
  EXPECT_EQ(64, num);
  EXPECT_EQ(32, blacks);
  EXPECT_EQ(32, reds);
}

TEST_F(BoardTest, DrawTest) {
  Board board;
//    m_board.Draw();
}

TEST_F(BoardTest, TestCoordToPoint) {
  Board board;
  UPoint p1 = board.coordToPoint("A7");
  EXPECT_EQ(0, p1.getX());
  EXPECT_EQ(0, p1.getY());

  UPoint p2 = board.coordToPoint("H0");
  EXPECT_EQ(7, p2.getX());
  EXPECT_EQ(7, p2.getY());
}

TEST_F(BoardTest, TestPointToCoord) {
  Board board;

  string coord1;
  coord1 = board.pointToCoord(UPoint(0, 0));
  EXPECT_EQ("A0", coord1);

  string coord2;
  coord2 = board.pointToCoord(UPoint(7, 7));
  EXPECT_EQ("H7", coord2);
}


#endif /* BoardTest_h */
