#include "Point.h"
#include <iostream>
#include <string>

using namespace std;

Point::Point(int xx){
    x = xx;
    y = 0;
}

Point::Point(int xx, int yy){
    x = xx;
    y = yy;
}

Point::Point(){
    x = 0;
    y = 0;
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);

}

