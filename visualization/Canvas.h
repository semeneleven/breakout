#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string>

#include "../geometry/Geometry.h"

class Canvas
{
public:
    Canvas(int height, int width, Box coordinates);

    std::string getImage();

    void clear();

    void drawPoint(Point point, char symbol);
    void drawLine(Point start, Point end, char symbol);

    bool getPixelPositionByPoint(Point point, int& heightIndex, int& widthIndex);

private:
    Box coordinates_;

    int height_;
    int width_;

    std::vector<std::string> picture_;    
};

#endif/*CANVAS_H*/