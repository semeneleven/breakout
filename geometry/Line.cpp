#include "Line.h"

#include "Vector.h"

double Line::getLength()
{
    Vector vector = point2_ - point1_;

    return vector.getLength();
}

std::vector<Point> Line::getApproximationPoints(int pointsQuantity)
{
    std::vector<Point> points;

    if (pointsQuantity < 1)
    {
        return points;
    }

    Vector approximationStep = point2_ - point1_;
    if (pointsQuantity == 1)
    {
        approximationStep /= 2;
        Point center = point1_;
        center += approximationStep;
        points.push_back(center);

        return points;
    }
    approximationStep /= pointsQuantity - 1;

    for (int i = 0; i < pointsQuantity; i++)
    {
        Point currentPoint = point1_ + approximationStep * i;
        points.push_back(currentPoint);
    }

    return points;
}