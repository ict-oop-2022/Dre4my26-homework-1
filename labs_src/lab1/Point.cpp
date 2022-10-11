#include "Point.h"

Point::Point() {
    _x = 0;
    _y = 0;
}

Point::Point(double x, double y) {
    _x = x;
    _y = y;
}

Point::Point(const Point &p) {
    _x = p._x;
    _y = p._y;
}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

void Point::setX(double x) {
    _x = x;
}

void Point::setY(double y) {
    _y = y;
}

void Point::setCoords(double x, double y) {
    _x = x;
    _y = y;
}