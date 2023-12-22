#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "coord.h"

#include <map>
#include <string>

class Rectangle {
public:
    Rectangle(Coord topLeft, int height, int width);
    Rectangle(Coord topLeft, Coord bottomRight);
    Rectangle(Coord top_left, Coord bottom_right, int height, int width);

    Rectangle& operator=(const Rectangle& other);

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

#endif // RECTANGLE_H
