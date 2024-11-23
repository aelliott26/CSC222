#ifndef POINT_H
#define POINT_H
#include <string>
using namespace std;

struct Point {
    int x, y;
    Point(int xx);
    Point(int xx, int yy);
    Point();
    Point operator+(const Point& other) const;


};

#endif
