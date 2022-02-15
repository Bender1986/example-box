#include <iostream>
#include <sstream>
#include "Operation.h"

/* Input Point */
std::istream& operator >> (std::istream &in, Point &point) {
          
      in >> point.x >> point.y;
      
      return in;
}


/* Check point to Line */
bool Line::operator^(const Point &point) {

    return ((point.x - pointBeg.x) * (pointEnd.y - pointBeg.y) == (point.y - pointBeg.y) * (pointEnd.x - pointBeg.x));
}


/* Check point equal */
bool Point::operator == (const Point &point) {

    return ((point.x == x) && (y == point.y));
}