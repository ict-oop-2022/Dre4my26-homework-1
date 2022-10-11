#ifndef ICT_HOMEWORK_1_TRAPEZOID_H
#define ICT_HOMEWORK_1_TRAPEZOID_H
#include "Polygon.h"


class Trapezoid : public Polygon {
public:
    explicit Trapezoid(const std::vector <Point> &points);
    bool isTrapezoid();
};


#endif //ICT_HOMEWORK_1_TRAPEZOID_H
