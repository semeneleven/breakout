#include "Point.h"

#include "Vector.h"

Point Point::operator+(const Point point) const
{
    Point result(x, y);

    result.x += point.x;
    result.y += point.y;

    return result;
}

Point Point::operator-(const Point point) const
{
    Point result(x, y);

    result.x -= point.x;
    result.y -= point.y;

    return result;
}

Point Point::operator+(const Vector vector) const
{
    Point result(x, y);

    result.x += vector.x;
    result.y += vector.y;

    return result;
}

Point Point::operator-(const Vector vector) const
{
    Point result(x, y);

    result.x -= vector.x;
    result.y -= vector.y;

    return result;
}

void Point::operator+=(const Vector vector)
{
    x += vector.x;
    y += vector.y;
}

void Point::operator-=(const Vector vector)
{
    x -= vector.x;
    y -= vector.y;
}