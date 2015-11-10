//
//  Game.h
//  Checkers
//
//  Created by Raul Villanueva on 11/5/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <ncurses.h>
#include <iostream>
#include "Board.h"
#include "Point.h"

// states definition
enum class GameState;
enum class PieceMovingState;
enum class CursorMoving;
enum class GameEvent;

struct Boundaries {
  unsigned minx;
  unsigned miny;
  unsigned maxx;
  unsigned maxy;
};

using std::cout;
using std::cin;
using UPoint = Point<unsigned>;

class Game {
 public:
  Game();
  ~Game();
  void run();

 private:
  Board m_board;
  GameState m_gamestate;
  PieceMovingState m_piecemoving;
  UPoint m_srcpos;
  UPoint m_destpos;
  WINDOW *m_win;
  UPoint m_cursorpos;
  UPoint m_boardpos;
  Boundaries m_boundaries;

 private:
  void processEvents();
  void processCommands(int ch);
  void processCursorMovement(int ch);
  void update();
  void render();
  void drawBoard();
  void drawBox(int y, int x, int height, int width);
  void drawStates();
  bool validateMove(UPoint src, UPoint dest);
};


enum class GameState {
  kNone,
  kGameRunning,
  kGameOver,
  kCount
};

enum class PieceMovingState {
  kStart = 0,
  kMovingPiece,
  kPieceMoved,
  kCount
};

enum class MoveDirection {
  kNone = 0,
  kMovingUp = 1,
  kMovingDown = 2,
  kMovingLeft = 4,
  kMovingRight = 8
};

enum class GameEvent {
  kNone = 0,

  // move events
      kMoveEvent,

  // misc
      kCancelCurrentOperation,
};

#endif /* Game_h */
