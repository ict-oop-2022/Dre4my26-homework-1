#ifndef ITMO_POINT_H
#define ITMO_POINT_H

class Point {
private:
    double _x;
    double _y;

public:
    Point();

    Point(double x, double y);

    Point(const Point &p);

    double getX() const;

    double getY() const;

    void setX(double x);

    void setY(double y);

    void setCoords(double x, double y);
};

#endif //ITMO_POINT_H
