//
//  TerminalSpriteTest.h
//  Checkers
//
//  Created by Raul Villanueva on 11/5/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef TerminalSpriteTest_h
#define TerminalSpriteTest_h

#include "gtest/gtest.h"
#include "TerminalSprite.h"

using testing::Test;

class TerminalSpriteTest : public Test {
};

TEST_F(TerminalSpriteTest, TestConstructor) {
    TerminalSprite tsprite;
    tsprite.clear('*');
//    tsprite.draw();
}

TEST_F(TerminalSpriteTest, TestDrawLine) {
    TerminalSprite tsprite;
    tsprite.clear('.');
    tsprite.renderLine('$', 0, 0, 0, 10);
    tsprite.renderLine('%', 2, 0, 4, 0);
//    tsprite.draw();
}

TEST_F(TerminalSpriteTest, TestDrawSquare) {
    TerminalSprite tsprite;
    tsprite.renderSquare('#', 0, 0, 10, 20);
    tsprite.renderSquare('@', 11, 10, 13, 12);
//    tsprite.draw();
}


#endif /* TerminalSpriteTest_h */
