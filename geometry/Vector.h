#ifndef BREAKOUT_VECTOR_H
#define BREAKOUT_VECTOR_H

#include "Point.h"

class Vector
{
public:
    Vector(double x=0, double y=0) : x(x), y(y) {};
    Vector(Point point) : x(point.x), y(point.y) {};

    void operator*=(const double value) {
        x *= value;
        y *= value;
    };
    Vector operator*(const double value) const{
        Vector result(x, y);

        result.x *= value;
        result.y *= value;

        return result;
    };

    void operator/=(const double value){
        x /= value;
        y /= value;
    };
    Vector operator/(const double value) const {
        Vector result(x, y);

        result.x /= value;
        result.y /= value;

        return result;
    }

    double getLength();
    void normalize();

    double x;
    double y;
};

#endif/*BREAKOUT_VECTOR_H*/