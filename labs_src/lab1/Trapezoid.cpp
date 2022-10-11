#include "Trapezoid.h"
#include <cassert>


Trapezoid::Trapezoid(const std::vector<Point> &points) : Polygon(points) {
    if (!isTrapezoid()) {
        throw std::invalid_argument("It's not a trapezoid");
    }
};

bool Trapezoid::isTrapezoid() {
    bool q = true, par1, par2;
    Point first, second, third, fourth;

    first = getVector(_pPoints[0], _pPoints[1]);
    second = getVector(_pPoints[1], _pPoints[2]);
    third = getVector(_pPoints[2], _pPoints[3]);
    fourth = getVector(_pPoints[3], _pPoints[4]);

    par1 = first.getX() * third.getY() - third.getX() * first.getY() == 0;
    par2 = second.getX() * fourth.getY() - fourth.getX() * second.getY() == 0;

    // если количество вершин не равно 4
    if (_pPoints.size() != 5 || !isConvex()) q = false;
    // если все стороны параллельны
    if (par1 && par2) {
        q = false;
    }
    // Если все стороны не параллельны
    if (not par1 && not par2) {
        q = false;
    }

    return q;
}

