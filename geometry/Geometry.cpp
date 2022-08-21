#include "Geometry.h"


bool Box::isPointInside(Point point) const
{
    bool insideByX = (point.x <= xMax_) && (point.x >= xMin_);
    bool insideByY = (point.y <= yMax_) && (point.y >= yMin_);
    return insideByX && insideByY;
}


void Box::getXRange(double& xMin, double& xMax) const
{
    xMin = xMin_;
    xMax = xMax_;
}

void Box::getYRange(double& yMin, double& yMax) const
{
    yMin = yMin_;
    yMax = yMax_;
}