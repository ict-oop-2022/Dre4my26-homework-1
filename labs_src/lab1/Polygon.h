#ifndef ITMO_POLYGON_H
#define ITMO_POLYGON_H

#include "ClosedPolyline.h"
#include <iostream>

class Polygon : protected ClosedPolyline {
public:
    Polygon();

    Polygon(const std::vector <Point> &points);

    Polygon(const Polygon &pg);

    bool isConvex();

    double getPerimeter();

    double getSquare();

    Point getVector(const Point &start, const Point &end);

    double getEdgeLength(const Point &start, const Point &end);
};

#endif //ITMO_POLYGON_H
