#ifndef ICT_HOMEWORK_1_TRIANGLE_H
#define ICT_HOMEWORK_1_TRIANGLE_H
#include "Polygon.h"

class Triangle : public Polygon {
public:
    explicit Triangle(const std::vector <Point> &points);
    bool isTriangle();
};


#endif //ICT_HOMEWORK_1_TRIANGLE_H
