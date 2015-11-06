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
#include "gtest/gtest.h"
#include "Board.h"


using testing::Test;
using std::string;

class BoardTest : public Test {
};

TEST_F(BoardTest, DrawTest) {
    Board board;
    board.Draw();
}

TEST_F(BoardTest, TestCoordToPoint) {
    Board board;
    Point p1 = board.coordToPoint("A7");
    EXPECT_EQ(0, p1.getX());
    EXPECT_EQ(0, p1.getY());

    Point p2 = board.coordToPoint("H0");
    EXPECT_EQ(7, p2.getX());
    EXPECT_EQ(7, p2.getY());
}

TEST_F(BoardTest, TestPointToCoord) {
    Board board;

    string coord1;
    coord1 = board.pointToCoord(Point(0, 0));
    EXPECT_EQ("A0", coord1);

    string coord2;
    coord2 = board.pointToCoord(Point(7, 7));
    EXPECT_EQ("H7", coord2);
}


#endif /* BoardTest_h */
