//
//  Point.h
//  Checkers
//
//  Created by Raul Villanueva on 11/2/15.
//  Copyright © 2015 Raul Villanueva. All rights reserved.
//

#ifndef Point_h
#define Point_h

#include <sstream>
#include <string>

using std::string;
using std::stringstream;


template<class T>
class Point {
 public:
  Point();
  Point(T newx, T newy);
  void set(T newx, T newy);
  void setX(T newx);
  T getX();
  void setY(T newy);
  T getY();
  Point operator+(const Point &b);
  Point operator-(const Point &b);
  string toString();
 private:
  T y;
  T x;
};


template<class T>
Point<T>::Point() {
  x = 0;
  y = 0;
}

template<class T>
Point<T>::Point(T newx, T newy) {
  x = newx;
  y = newy;
}

template<class T>
void Point<T>::setX(T newx) {
  x = newx;
}

template<class T>
T Point<T>::getX() {
  return x;
}

template<class T>
void Point<T>::setY(T newy) {
  y = newy;
}

template<class T>
void Point<T>::set(T newx, T newy) {
  x = newx;
  y = newy;
}

template<class T>
T Point<T>::getY() {
  return y;
}

template<class T>
string Point<T>::toString() {
  stringstream ss;
  ss << "Point<" << getX() << ", " << getY() << ">";
  return ss.str();
}

template<class T>
Point<T> Point<T>::operator+(const Point<T> &p) {
  Point<T> point;
  point.x = this->x + p.x;
  point.y = this->y + p.y;
  return point;
}

template<class T>
Point<T> Point<T>::operator-(const Point<T> &p) {
  Point<T> point;
  point.x = this->x - p.x;
  point.y = this->y - p.y;
  return point;
}


#endif /* Point_h */
