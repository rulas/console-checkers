//
// Created by Raul Villanueva on 11/6/15.
//

#include <string>
#include "Color.h"

using std::string;

string ColorStr::toString(colors color) {
  if (color == colors::red) {
    return "red";
  } else if (color == colors::black) {
    return "black";
  } else if (color == colors::white) {
    return "white";
  }

  return "none";
}
