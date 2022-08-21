#include "Vector.h"

#include <tgmath.h>

double Vector::getLength()
{
    return sqrt(x*x + y*y);
}

void Vector::normalize()
{
    double length = getLength();

    if (length != 0)
    {
        x /= length;
        y /= length;
    }
}