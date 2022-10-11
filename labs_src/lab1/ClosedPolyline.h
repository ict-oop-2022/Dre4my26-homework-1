#ifndef ITMO_CLOSEDPOLYLINE_H
#define ITMO_CLOSEDPOLYLINE_H

#include "Polyline.h"


class ClosedPolyline : public Polyline {
public:
    ClosedPolyline();

    ClosedPolyline(const std::vector <Point> &points);

    ClosedPolyline(const ClosedPolyline &cPLine);

    void addPoint(double x, double y);

    void addPoint(const Point &p) override;
};


#endif //ITMO_CLOSEDPOLYLINE_H
