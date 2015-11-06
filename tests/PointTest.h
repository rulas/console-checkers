//
//  TestPoint.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef TestPoint_h
#define TestPoint_h

#include "Point.h"
#include "gtest/gtest.h"
#include <iostream>

using testing::Test;
using std::cout;
using std::endl;

class PointTest : public Test {
};

TEST_F(PointTest, HelloTest) {
    Point p(10, 20);
    EXPECT_EQ(10, p.getX());
    EXPECT_EQ(20, p.getY());
}


#endif /* TestPoint_h */
