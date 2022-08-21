#include "Canvas.h"


Canvas::Canvas(int height, int width, Box coordinates)
{
    height_ = height;
    width_ = width;
    coordinates_ = coordinates;

    for (int i = 0; i < height; i++)
        picture_.push_back(std::string(width, ' '));
}


std::string Canvas::getImage()
{
    std::string image;

    for (std::string row : picture_)
        image += row + "\n";

    return image;
}


void Canvas::clear()
{
    picture_.clear();

    for (int i = 0; i < height_; i++)
        picture_.push_back(std::string(" ", width_));
}


bool Canvas::getPixelPositionByPoint(Point point, int& heightIndex, int& widthIndex)
{
    if (!coordinates_.isPointInside(point))
        return false;
        
    double xMin, xMax, yMin, yMax;
    coordinates_.getXRange(xMin, xMax);
    coordinates_.getYRange(yMin, yMax);

    double xRelative = (point.x - xMin) / (xMax - xMin);
    double yRelative = (point.y - yMin) / (yMax - yMin);

    xRelative *= width_ - 1;
    yRelative *= height_ - 1;

    widthIndex = static_cast<int>(round(xRelative));
    heightIndex = (height_ - 1) - static_cast<int>(round(yRelative));

    return true;
}


void Canvas::drawPoint(Point point, char symbol)
{
    int heightIndex, widthIndex;
    if (getPixelPositionByPoint(point, heightIndex, widthIndex))
        picture_[heightIndex][widthIndex] = symbol;
}


void Canvas::drawLine(Point start, Point end, char symbol)
{
    int startHeight, startWidth, endHeight, endWidth;
    bool startInside = getPixelPositionByPoint(start, startHeight, startWidth);
    bool endInside = getPixelPositionByPoint(end, endHeight, endWidth);

    if (startInside && endInside)
    {
        int widthRange = endWidth - startWidth;
        int heightRange = endHeight - startHeight;

        int length = (int)MAX(fabs(widthRange), fabs(heightRange));
        double dWidth = widthRange / length;
        double dHeight = heightRange / length;

        double currentHeight = startHeight;
        double currentWidth = startWidth;
        for (int i = 0; i < length; i++)
        {
            currentHeight += dHeight;
            currentWidth += dWidth;
            int heightIndex = static_cast<int>(round(currentHeight));
            int widthIndex = static_cast<int>(round(currentWidth));
            picture_[heightIndex][widthIndex] = symbol;
        }
    }
}