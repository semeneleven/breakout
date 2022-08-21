#ifndef BREAKOUT_GEOMETRY_H
#define BREAKOUT_GEOMETRY_H

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

class Vector
{
public:
    Vector(double x=0, double y=0) : x(x), y(y) {};

    double x;
    double y;
};

class Point
{
public:
    Point(double x=0, double y=0) : x(x), y(y) {};

    void operator+(Vector vector){
        x += vector.x;
        y += vector.y;
    };

    double x;
    double y;
};

class Box
{
public:
    Box() {
        xMin_ = 0;
        xMax_ = 0;
        yMin_ = 0;
        yMax_ = 0;
    }
    Box(Point point1, Point point2) {
        xMin_ = MIN(point1.x, point2.x);
        xMax_ = MAX(point1.x, point2.x);
        yMin_ = MIN(point1.y, point2.y);
        yMax_ = MAX(point1.y, point2.y);
    };

    void getXRange(double& xMin, double& xMax) const;
    void getYRange(double& yMin, double& yMax) const;

    bool isPointInside(Point point) const;

private:
    double xMin_;
    double xMax_;
    double yMin_;
    double yMax_;
};

#endif/*BREAKOUT_GEOMETRY_H*/