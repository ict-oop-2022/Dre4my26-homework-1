#ifndef ITMO_POLYLINE_H
#define ITMO_POLYLINE_H

#include "Point.h"
#include <cmath>
#include <vector>

class Polyline {
protected:
    int _sz = 0;

    std::vector <Point> _pPoints;
public:
    Polyline();

    explicit Polyline(const std::vector <Point> &points);

    Polyline(Polyline const &pLine);

    double getLineLength();

    void getLine();

    virtual void addPoint(double x, double y);

    virtual void addPoint(const Point &p);

    void addPoints(const std::vector <Point> &points);

    bool checkClosed();

    int getSize();
};

#endif //ITMO_POLYLINE_H
