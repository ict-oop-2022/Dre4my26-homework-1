#include "Polygon.h"


Polygon::Polygon() = default;

Polygon::Polygon(const std::vector<Point> &points) : ClosedPolyline(points){}

Polygon::Polygon(const Polygon &pg) {
    _pPoints = pg._pPoints;
    _sz = pg._sz;
}

bool Polygon::isConvex() {
    double t, k;
    Point start, end;
    bool q = true;

    start = getVector(_pPoints[0], _pPoints[1]);
    end = getVector(_pPoints[_sz - 2], _pPoints[_sz - 1]);
    t = end.getX() * start.getY() - start.getX() * end.getY();
    t = t / std::abs(t);

    for (int i = 0; i < _sz - 2 && q; i++) {
        start = getVector(_pPoints[i], _pPoints[i + 1]);
        end = getVector(_pPoints[i + 1], _pPoints[i + 2]);
        k = start.getX() * end.getY() - end.getX() * start.getY();
        k = k / std::abs(k);
        if (k != t) {
            q = false;
        }
    }

    return q;
}

double Polygon::getPerimeter() {
    return Polyline::getLineLength();
}

double Polygon::getSquare() {
    double s = 0;
    s += _pPoints[0].getY() * _pPoints[_sz - 1].getX() - _pPoints[0].getX() * _pPoints[_sz - 1].getY();
    for (int i = 0; i < _sz - 2; i++) {
        s += _pPoints[i].getX() * _pPoints[i + 1].getY() - _pPoints[i].getY() * _pPoints[i + 1].getX();
    }
    return std::abs(s) * 0.5;
}

Point Polygon::getVector(const Point &start, const Point &end) {
    return Point(end.getX() - start.getX(), end.getY() - start.getY());
}

double Polygon::getEdgeLength(const Point &start, const Point &end) {
    return sqrt(pow(end.getX() - start.getX(), 2) + pow(end.getY() - start.getY(), 2));
}

