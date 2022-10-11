#include "RegularPolygon.h"
#include <cassert>


RegularPolygon::RegularPolygon(const std::vector<Point> &points) : Polygon(points) {
    assert(isRegular() && "It's not a regular polygon");
}

bool RegularPolygon::isRegular() {
    bool q = isConvex();
    Point first = getVector(_pPoints[0], _pPoints[1]);
    Point second = getVector(_pPoints[1], _pPoints[2]);
    double t = getEdgeLength(_pPoints[0], _pPoints[1]);
    double angle = (first.getX() * second.getX() + first.getY() * second.getY()) /
                   (getEdgeLength(_pPoints[0], _pPoints[1]) * getEdgeLength(_pPoints[1], _pPoints[2]));

    for (int i = 1; i < _sz - 2; i++) {
        if (getEdgeLength(_pPoints[i], _pPoints[i + 1]) != t) {
            return false;
        }
    }

    for (int i = 2; i < _sz - 2; i++) {
        first = getVector(_pPoints[i], _pPoints[i + 1]);
        second = getVector(_pPoints[i + 1], _pPoints[i + 2]);

        if ((first.getX() * second.getX() + first.getY() * second.getY()) /
            (getEdgeLength(_pPoints[0], _pPoints[1]) * getEdgeLength(_pPoints[1], _pPoints[2])) != angle) {
            return false;
        }
    }

    return true;
}