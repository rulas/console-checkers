//
// Created by Raul Villanueva on 11/6/15.
//

#include <ncurses.h>
#include "Game.h"


Game::Game() {
  m_gamestate = GameState::kNone;
  m_piecemoving = PieceMovingState::kStart;

  // m_board position
  m_boardpos.set(10, 10);

  // ncurses initialization
  m_win = nullptr;
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  //update boundaries
  m_boundaries = {0, 0, 0, 0};
  getmaxyx(stdscr, m_boundaries.maxy, m_boundaries.maxx);
}

Game::~Game() {
  endwin();
}

void Game::run() {
  m_gamestate = GameState::kGameRunning;
  while (m_gamestate == GameState::kGameRunning) {
    processEvents();
    update();
    render();
  }

}

void Game::processEvents() {
  int ch;

  timeout(0);
  ch = getch();
  if (ch == 'q' || ch == ' ') {
    processCommands(ch);
  } else if ((ch == KEY_UP) || (ch == KEY_DOWN) || (ch == KEY_LEFT) || (ch == KEY_RIGHT)) {
    processCursorMovement(ch);
  } else {
    if (ch != ERR) {
      mvprintw(0, 0, "Key not supported yet.");
    }
  }
}

void Game::processCommands(int ch) {
  switch (ch) {
    case 'q': {
      mvprintw(0, 0, "F1 Key pressed. Game Over!");
      m_gamestate = GameState::kGameOver;
      break;
    }
    case ' ': {
      switch (m_piecemoving) {
        // a space is intended to move a piece
        case PieceMovingState::kStart: {

          m_srcpos = m_cursorpos - m_boardpos;
          Square square;
          square = m_board.getSquareAt(m_srcpos);

          if (square.hasPiece()) {
            Piece *pPiece = square.getPiece();
            mvprintw(0, 0, "moving piece at <%d, %d> color: %s",
                     m_srcpos.getY(), m_srcpos.getX(),
                     ColorStr::toString(pPiece->getColor()).c_str());
          } else {
            mvprintw(0, 0, "ERROR: no piece at current position");
          }
          m_piecemoving = PieceMovingState::kMovingPiece;
          break;
        }

        case PieceMovingState::kMovingPiece: {
          m_destpos = m_cursorpos - m_boardpos;
          mvprintw(0, 0, "moving piece from <%d,%d> to <%d,%d>",
                   m_srcpos.getY(),
                   m_srcpos.getX(),
                   m_destpos.getY(),
                   m_destpos.getX()
          );

          m_piecemoving = PieceMovingState::kPieceMoved;
          break;
        }
        case PieceMovingState::kPieceMoved: {
          break;
        }
        case PieceMovingState::kCount: {
          // dummy case to avoid compiler warnings
          break;
        }
      }
    }
  }
}

void Game::processCursorMovement(int ch) {

  // adjust current position while checking for boundaries
  switch (ch) {
    case KEY_UP:
      if (m_cursorpos.getY() != m_boundaries.miny) {
        m_cursorpos.setY(m_cursorpos.getY() - 1);
      }
      break;
    case KEY_DOWN:
      if (m_cursorpos.getY() != m_boundaries.maxy) {
        m_cursorpos.setY(m_cursorpos.getY() + 1);
      }
      break;
    case KEY_LEFT:
      if (m_cursorpos.getX() != m_boundaries.minx) {
        m_cursorpos.setX(m_cursorpos.getX() - 1);
      }
      break;
    case KEY_RIGHT:
      if (m_cursorpos.getX() != m_boundaries.maxx) {
        m_cursorpos.setX(m_cursorpos.getX() + 1);
      }
      break;
  }
}

void Game::update() {
}

void Game::render() {
  // print current position
  mvprintw(int(m_boundaries.maxy) - 1, 0, "currenPos:%2d,%2d", m_cursorpos.getY(), m_cursorpos.getX());

  drawStates();
  drawBoard();

  // moved to cursor position
  move(int(m_cursorpos.getY()), int(m_cursorpos.getX()));
  refresh();
}

void Game::drawBox(int y, int x, int height, int width) {
  mvaddch(y, x, ACS_ULCORNER);
  mvaddch(y, x + width + 1, ACS_URCORNER);
  mvaddch(y + height + 1, x, ACS_LLCORNER);
  mvaddch(y + height + 1, x + width + 1, ACS_LRCORNER);
  mvhline(y, x + 1, ACS_HLINE, width);
  mvhline(y + height + 1, x + 1, ACS_HLINE, width);
  mvvline(y + 1, x, ACS_VLINE, height);
  mvvline(y + 1, x + width + 1, ACS_VLINE, height);
  move(y, x);
}

void Game::drawBoard() {
  UPoint boxpos(m_boardpos.getX() - 1, m_boardpos.getY() - 1);
  UPoint newpos;

  // draw a box starting at (-1, -1) offset of actual m_board
  drawBox(int(boxpos.getY()), int(boxpos.getX()), 8, 8);

  for (auto squares: m_board.getSquares()) {
    for (auto square: squares) {
      newpos = m_boardpos + square.getPosition();
      if (square.getColor() == colors::red) {
        mvaddch(newpos.getY(), newpos.getX(), ' ');
      } else {
        attron(A_REVERSE);
        if (square.hasPiece()) {
          if (square.getPiece()->getColor() == colors::black) {
            mvaddch(newpos.getY(), newpos.getX(), 'b');
            attron(A_REVERSE);
          } else if (square.getPiece()->getColor() == colors::white) {
            mvaddch(newpos.getY(), newpos.getX(), 'w');
          }
        }
        else {
          mvaddch(newpos.getY(), newpos.getX(), ' ');
        }
        attroff(A_REVERSE);
      }
    }
  }
}


void Game::drawStates() {
  int x = 40;
  int y = 40;

  mvprintw(y++, x, "GameState: %d", m_gamestate);
  mvprintw(y, x, "PieceMovingState: %d", m_piecemoving);
}

bool Game::validateMove(UPoint src, UPoint dest) {
  src = dest;
  return false;
}
