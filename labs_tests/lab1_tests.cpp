#include <gtest/gtest.h>

#include "lab1/Point.h"
#include "lab1/Polyline.h"
#include "lab1/ClosedPolyline.h"
#include "lab1/Polygon.h"
#include "lab1/Triangle.h"
#include "lab1/Trapezoid.h"
#include "lab1/RegularPolygon.h"

TEST(CreatePoint, CheckPointGetter) {
Point p(1, 2);
ASSERT_EQ(1, p.getX());
ASSERT_EQ(2, p.getY());
}

TEST(CreatePolyline, CheckLengthAndAddPoint) {
std::vector <Point> points = {
        Point(0, 0),
        Point(0, 2),
        Point(2, 2)
};
std::vector <Point> ap = {Point(0,0), Point(0, -2)};
Polyline pl(points);
pl.addPoint(Point(2, 0));
pl.addPoints(ap);
pl.addPoint(2, -2);
ASSERT_EQ(12, pl.getLineLength()) << "ERROR: " << pl.getLineLength() << " is not 4";
}

TEST(CreateClosedPolyline, CheckClosed) {
std::vector <Point> points = {
        Point(0, 0),
        Point(0, 2),
        Point(2, 2),
};
ClosedPolyline cpl(points);
ASSERT_EQ(true, cpl.checkClosed());
}

TEST(CreatePolygon, CheckGetPerimeter){
std::vector <Point> points = {
        Point(0, 0),
        Point(0, 2),
        Point(2, 2),
        Point(2, 0)
};
Polygon pl(points);
ASSERT_EQ(8, pl.getPerimeter());
}

TEST(CreatePolygon, CheckGetSquare){
std::vector <Point> points = {
        Point(0, 0),
        Point(0, 2),
        Point(2, 2),
        Point(2, 0)
};
Polygon pl(points);
ASSERT_EQ(4, pl.getSquare());
}

TEST(CreatePolygon, CheckIsConvex){
std::vector <Point> points1 = {
        Point(0, 0),
        Point(0, 2),
        Point(2, 4),
        Point(4, 2),
        Point(4, 0),
        Point(2, -1)
};
std::vector <Point> points2 = {
        Point(0, 0),
        Point(0, 2),
        Point(2, 4),
        Point(4, 2),
        Point(4, 0),
        Point(2, 1)
};
Polygon pl1(points1);
Polygon pl2(points2);
ASSERT_EQ(true, pl1.isConvex());
ASSERT_EQ(false, pl2.isConvex());
}

TEST(CreateTriangle, CheckIsTriangle){
std::vector <Point> points = {
        Point(0, 0),
        Point(2, 3),
        Point(4, 0)
};
Triangle tr(points);
ASSERT_EQ(true, tr.isTriangle());
}

TEST(CreateTriangle, CheckIsTriangle_ThrowException){
std::vector <Point> points2 = {
        Point(0, 0),
        Point(0, 3),
        Point(0, 2)
};
ASSERT_ANY_THROW(Triangle tr2(points2));
}

TEST(CreateTrapezoid, CheckIsTrapezoid){
std::vector <Point> points = {
        Point(0, 0),
        Point(1, 3),
        Point(3, 3),
        Point(4, 0)
};
Trapezoid tr(points);
ASSERT_EQ(true, tr.isTrapezoid());
}

TEST(CreateTrapezoid, CheckIsTrapezoid_ThrowException){
std::vector <Point> points = {
        Point(0, 0),
        Point(1, 3),
        Point(3, 2),
        Point(4, 0)
};
ASSERT_ANY_THROW(Trapezoid tr(points));
}

TEST(CreateRegularPolygon, CheckIsRegular){
std::vector <Point> points = {
        Point(0, 0),
        Point(0, 2),
        Point(2, 2),
        Point(2, 0)
};
RegularPolygon pl(points);
ASSERT_EQ(true, pl.isRegular());
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

