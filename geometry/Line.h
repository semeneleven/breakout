#ifndef BREAKOUT_LINE_H
#define BREAKOUT_LINE_H

#include <vector>

#include "Point.h"

class Line
{
public:
    Line(Point point1, Point point2) : point1_(point1), point2_(point2) {};

    Point getPoint1() {
        return point1_;
    };
    Point getPoint2() {
        return point2_;
    };

    double getLength();
    std::vector<Point> getApproximationPoints(int pointsQuantity);

private:
    Point point1_;
    Point point2_;
};

#endif/*BREAKOUT_LINE_H*/