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

using testing::Test;

class SquareTest : public Test{
};

TEST_F(SquareTest, DefaultConstructor) {
    Square *s = new Square();
    EXPECT_EQ(colors::red, s->getColor());
    EXPECT_EQ(0, s->getPosition().getX());
    EXPECT_EQ(0, s->getPosition().getY());
}

TEST_F(SquareTest, SimpleInitRed) {
    Square *s = new Square(colors::red, Point(10, 20));
    EXPECT_EQ(colors::red, s->getColor());
    EXPECT_EQ(10, s->getPosition().getX());
    EXPECT_EQ(20, s->getPosition().getY());
}

TEST_F(SquareTest, SimpleInitBlack) {
    Square *s = new Square(colors::black, Point(10, 20));
    EXPECT_EQ(colors::black, s->getColor());
    EXPECT_EQ(10, s->getPosition().getX());
    EXPECT_EQ(20, s->getPosition().getY());
}


#endif /* SquareTest_h */
