#include "Polyline.h"
#include <iostream>


Polyline::Polyline() = default;

Polyline::Polyline(const std::vector <Point>& points) {
    for (const auto& point : points) {
        _pPoints.push_back(point);
    }
    _sz = points.size();
}

Polyline::Polyline(Polyline const &pLine) {
    _pPoints = pLine._pPoints;
    _sz = _pPoints.size();
}

double Polyline::getLineLength() {
    double length = 0;
    for (int i = 0; i < _pPoints.size() - 1; i++) {
        length += sqrt(pow(_pPoints[i + 1].getX() - _pPoints[i].getX(), 2) +
                       pow(_pPoints[i + 1].getY() - _pPoints[i].getY(), 2));
    }
    return length;
}

void Polyline::getLine() {
    if (_pPoints.empty()) {
        std::cout << "Ломаная не создана\n";
    }
    for (auto point : _pPoints) {
        std::cout << '(' << point.getX() << "; " << point.getY() << ")\n";
    }
}

void Polyline::addPoint(double x, double y) {
    _pPoints.emplace_back(x, y);
    _sz++;
}

void Polyline::addPoint(const Point& p) {
    _pPoints.push_back(p);
    _sz++;
}

void Polyline::addPoints(const std::vector<Point> &points) {
    for (const auto& point : points) {
        _pPoints.push_back(point);
        _sz++;
    }
}

bool Polyline::checkClosed() {
    return _pPoints[0].getX() == _pPoints[_sz - 1].getX() &&
           _pPoints[0].getY() == _pPoints[_sz - 1].getY();
}

int Polyline::getSize() {
    return _pPoints.size();
}