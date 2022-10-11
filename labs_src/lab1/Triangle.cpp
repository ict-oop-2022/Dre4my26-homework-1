#include "Triangle.h"
#include <cassert>


Triangle::Triangle(const std::vector<Point> &points) : Polygon(points) {
    if (!isTriangle()) {
        throw std::invalid_argument("It's not a triangle.");
    }
};

bool Triangle::isTriangle() {
    return _pPoints.size() == 4 && isConvex();
}