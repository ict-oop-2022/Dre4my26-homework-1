#ifndef ICT_HOMEWORK_1_REGULARPOLYGON_H
#define ICT_HOMEWORK_1_REGULARPOLYGON_H
#include "Polygon.h"

class RegularPolygon : public Polygon {
public:
    explicit RegularPolygon(const std::vector <Point> &points);
    bool isRegular();
};


#endif //ICT_HOMEWORK_1_REGULARPOLYGON_H
