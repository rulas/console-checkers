//
//  Board.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef CheckersBoard_h
#define CheckersBoard_h

#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <string>
#include "Square.h"
#include "Piece.h"
#include "TerminalSprite.h"

using std::cout;
using std::endl;
using std::vector;
using std::stoi;

const int kCols = 8;
const int kRows = 8;


class Board {

 public:
    Board() {
        height = kRows;
        width = kCols;
        Init();
    }

    void Init() {
        // creates neccesary squares
        for (int y = 0; y < height; y++) {
            vector<Square> row;
            for (int x = 0; x < width; x++) {
                if ((y % 2) ^ (x % 2)) {
                    row.push_back(Square(colors::black, Point(x, y)));
                } else {
                    row.push_back(Square(colors::red, Point(x, y)));
                }
            }
            matrix.push_back(row);
        }
    }

    void Setup() {
    }

    void Draw() {
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[y].size(); x++) {
                Square *s = &matrix[y][x];
                if (s->getColor() == colors::red) {
                    cout << " ";
                } else {
                    cout << "#";
                }
            }
            cout << endl;
        }
    }

    string pointToCoord(Point point) {
        char xcoord;
        char ycoord;
        string coord;

        xcoord = 'A' + static_cast<char>(point.getX());
        ycoord = '0' + static_cast<char>(point.getY());

        coord += xcoord;
        coord += ycoord;

        return coord;
    }

    Point coordToPoint(string coord) {
        char xcoord = static_cast<char>(toupper(coord[0]));
        char ycoord = coord[1];
        // "A" = 0, "B" = 1, "C" = 2, "D" = 3, ...
        // 0 = 7, 1 = 6, 2 = 5, 3 = 4, ..
        int xpoint = xcoord - 'A';
        int ypoint = abs(ycoord - '0' - 7);

        return Point(xpoint, ypoint);
    }

 private:
    int height;
    int width;
    vector<vector<Square>> matrix;
    vector<vector<Piece>> pieces;
};


#endif /* CheckersBoard_h */
