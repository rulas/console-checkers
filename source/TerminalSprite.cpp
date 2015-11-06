//
// Created by Raul Villanueva on 11/6/15.
//

#include "TerminalSprite.h"


void TerminalSprite::clear() {
    clear(' ');
}

void TerminalSprite::clear(unsigned char newchar) {
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++) {
            matrix[row][col] = newchar;
        }
    }
}


bool TerminalSprite::validRow(int row) {
    return (row >= 0 && row < rows) ? true : false;
}

bool TerminalSprite::validCol(int col) {
    return (col >= 0 && col < cols) ? true : false;
}

void TerminalSprite::renderHLine(unsigned char newchar, int startrow, int startcol, int lenght) {
    renderLine(newchar, startrow, startcol, startrow, startcol+lenght-1);
}

void TerminalSprite::renderVLine(unsigned char newchar, int startrow, int startcol, int lenght) {
    renderLine(newchar, startrow, startcol, startrow+lenght-1, startcol);
}

void TerminalSprite::renderLine(unsigned char newchar, int startrow, int startcol, int endrow, int endcol) {
    // adding validation
    assert(validRow(startrow));
    assert(validCol(startcol));
    assert(validRow(endrow));
    assert(validCol(endcol));

    if (startrow == endrow){
        // horizontal line
        for (int col = startcol; col <= endcol; col++) {
            matrix[startrow][col] = newchar;
        }
    } else if (startcol == endcol) {
        // vertical line
        for (int row = startrow; row <= endrow; row++) {
            matrix[row][startcol] = newchar;
        }
    } else {
        // not supported yet
    }

}

void TerminalSprite::renderPoint(unsigned char newchar, int row, int col) {
    assert(validRow(row));
    assert(validCol(col));
    matrix[row][col] = newchar;
}

void TerminalSprite::renderSquare(unsigned char newchar, int startrow, int startcol, int endrow, int endcol) {
    // top line
    renderHLine(newchar, startrow, startcol, endcol - startcol + 1);

    // bottom line
    renderHLine(newchar, endrow, startcol, endcol - startcol + 1);

    // left line
    renderVLine(newchar, startrow, startcol, endrow - startrow + 1);

    // right line
    renderVLine(newchar, startrow, endcol, endrow - startrow + 1);
}


void TerminalSprite::draw() {
//    for (int row = 0; row < rows; row++){
//        for (int col = 0; col < cols; col++) {
//            cout.put(matrix[row][col]);
//        }
//        cout << endl;
//    }
    cout << toString() << endl;
}

string TerminalSprite::toString() {
    stringstream ss;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            ss.put(matrix[row][col]);
        }
        ss << endl;
    }

    return ss.str();
}
