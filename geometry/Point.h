#ifndef BREAKOUT_POINT_H
#define BREAKOUT_POINT_H

class Vector;

class Point
{
public:
    Point(double x=0, double y=0) : x(x), y(y) {};

    Point operator+(const Point point) const;
    Point operator-(const Point point) const;

    Point operator+(const Vector vector) const;
    Point operator-(const Vector vector) const;

    void operator+=(const Vector vector);
    void operator-=(const Vector vector);

    double x;
    double y;
};

#endif/*BREAKOUT_POINT_H*/