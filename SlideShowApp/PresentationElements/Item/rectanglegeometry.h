#ifndef RECTANGLEGEOMETRY_H
#define RECTANGLEGEOMETRY_H

#include "coord.h"

#include <map>
#include <string>

class RectangleGeometry
{
public:
    RectangleGeometry(Coord topLeft, int height, int width);
    RectangleGeometry(Coord topLeft, Coord bottomRight);
    RectangleGeometry(Coord top_left, Coord bottom_right, int height, int width);
    RectangleGeometry(Coord top_left, int height);

    RectangleGeometry& operator=(const RectangleGeometry& other);

    Coord getTopLeft() const;
    Coord getBottomRight() const;
    int getHeight() const;
    int getWidth() const;

    void setTopLeft(Coord newTopLeft);
    void setBottomRight(Coord newBottomRight);
    void setHeight(int newHeight);
    void setWidth(int newWidth);

    void revertToLatestParameters();
    void changeParameters(std::map<std::string, std::string> options);
    void saveParametersLatestVersion();

private:
    Coord topLeft;
    Coord bottomRight;
    int height;
    int width;
    std::map<std::string, std::variant<Coord, int>> prevParameters;
};

#endif // RECTANGLEGEOMETRY_H
