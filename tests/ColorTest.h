//
//  ColorTest.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef ColorTest_h
#define ColorTest_h

#include "gtest/gtest.h"
#include "Color.h"

using testing::Test;

class ColorTest: public Test {
};

TEST_F(ColorTest, toStringTest) {
  colors color = colors::red;
  EXPECT_EQ(colors::red, color);

  EXPECT_EQ("none", ColorStr::toString(colors::none));
  EXPECT_EQ("red", ColorStr::toString(colors::red));
  EXPECT_EQ("black", ColorStr::toString(colors::black));
}


#endif /* ColorTest_h */
