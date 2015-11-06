//
//  Game.h
//  Checkers
//
//  Created by Raul Villanueva on 11/5/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <iostream>
#include "Board.h"

using std::cout;
using std::cin;
using std::endl;

class Game {
 public:

    Game();
    void run();
 private:
    Board board;

 private:
    void processEvents();
    void update();
    void render();
};



#endif /* Game_h */
