//
//  TestPoint.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef TestPoint_h
#define TestPoint_h

#include <iostream>
#include "Point.h"
#include "gtest/gtest.h"

using UPoint = Point<unsigned>;

using testing::Test;
using std::cout;
using std::endl;

class PointTest: public Test {
};

TEST_F(PointTest, HelloTest) {
  UPoint p(10, 20);
  EXPECT_EQ(10, p.getX());
  EXPECT_EQ(20, p.getY());
}

TEST_F(PointTest, OffsetTest) {
  UPoint p1(10, 10);
  UPoint p2(0, 0);
  UPoint p3;

  p3 = p1 + p2;
  EXPECT_EQ(10, p3.getX());
  EXPECT_EQ(10, p3.getY());

  p3 = p1 + UPoint(10, 10);
  EXPECT_EQ(20, p3.getX());
  EXPECT_EQ(20, p3.getY());
}


#endif /* TestPoint_h */
