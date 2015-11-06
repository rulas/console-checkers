//
//  main.cpp
//  Tests
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "TerminalSpriteTest.h"
#include "ColorTest.h"
#include "PointTest.h"
#include "SquareTest.h"
#include "PieceTest.h"
#include "BoardTest.h"
#include "GameTest.h"


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
