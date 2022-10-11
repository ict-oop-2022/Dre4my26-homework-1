#include "ClosedPolyline.h"
#include <iostream>

ClosedPolyline::ClosedPolyline() = default;

ClosedPolyline::ClosedPolyline(const std::vector<Point> &points) {
    for (const auto& point : points) {
        _pPoints.push_back(point);
    }
    _sz = _pPoints.size();
    if (points[0].getX() != points[_sz - 1].getX() || points[0].getY() != points[_sz - 1].getY()) {
        _pPoints.push_back(_pPoints[0]);
        _sz++;
    }
}

ClosedPolyline::ClosedPolyline(const ClosedPolyline &cPLine)  : Polyline(cPLine) {
    _pPoints = cPLine._pPoints;
    _sz = cPLine._sz;
}

void ClosedPolyline::addPoint(double x, double y) {
    _pPoints[_sz - 1] = Point(x, y);
    _pPoints.push_back(_pPoints[0]);
}

void ClosedPolyline::addPoint(const Point& p) {
    _pPoints[_sz - 1] = p;
    _pPoints.push_back(_pPoints[0]);
}

