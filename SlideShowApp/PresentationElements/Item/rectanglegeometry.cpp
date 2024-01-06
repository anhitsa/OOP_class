#include "rectanglegeometry.h"

RectangleGeometry::RectangleGeometry(Coord topLeft, int height, int width)
    : topLeft(topLeft), height(height), width(width)
{
    bottomRight = Coord(topLeft.getX() + width, topLeft.getY() + height);
}

RectangleGeometry::RectangleGeometry(Coord topLeft, Coord bottomRight)
    : topLeft(topLeft), bottomRight(bottomRight)
{
    height = bottomRight.getY() - topLeft.getY();
    width = bottomRight.getX() - topLeft.getX();
}

RectangleGeometry::RectangleGeometry(Coord topLeft, Coord bottomRight, int height, int width)
    : topLeft(topLeft), bottomRight(bottomRight), height(height), width(width)
{

}

RectangleGeometry::RectangleGeometry(Coord topLeft, int height)
    : topLeft(topLeft), height(height), width(height)
{
    bottomRight = Coord(topLeft.getX() + width, topLeft.getY() + height);
}

Coord RectangleGeometry::getTopLeft() const
{
    return topLeft;
}

Coord RectangleGeometry::getBottomRight() const
{
    return bottomRight;
}

int RectangleGeometry::getHeight() const
{
    return height;
}

int RectangleGeometry::getWidth() const
{
    return width;
}

void RectangleGeometry::setTopLeft(Coord newTopLeft)
{
    topLeft = newTopLeft;
}

void RectangleGeometry::setBottomRight(Coord newBottomRight)
{
    bottomRight = newBottomRight;
}

void RectangleGeometry::setHeight(int newHeight)
{
    height = newHeight;
}

void RectangleGeometry::setWidth(int newWidth)
{
    width = newWidth;
}

RectangleGeometry& RectangleGeometry::operator=(const RectangleGeometry& other)
{
    if (this == &other)
        return *this;

    topLeft = other.topLeft;
    bottomRight = other.bottomRight;
    width = other.width;
    height = other.height;
    return *this;
}

void RectangleGeometry::revertToLatestParameters()
{
    topLeft = std::get<Coord>(prevParameters.find("top_left")->second);
    bottomRight = std::get<Coord>(prevParameters.find("bottom_right")->second);;
    height = std::get<int>(prevParameters.find("height")->second);
    width = std::get<int>(prevParameters.find("width")->second);
}

void RectangleGeometry::saveParametersLatestVersion()
{
    prevParameters["top_left"] = topLeft;
    prevParameters["bottom_right"] = bottomRight;
    prevParameters["height"] = height;
    prevParameters["width"] = width;
}

void RectangleGeometry::changeParameters(std::map<std::string, std::string> options)
{
    saveParametersLatestVersion();
    std::map<std::string, std::function<void(const std::string&)>> parameterMap = {
                                                                                    {"height", [this](const std::string& value) { height = std::stoi(value); }},
                                                                                    {"width", [this](const std::string& value) { width = std::stoi(value); }},
                                                                                    {"top_left", [this](const std::string& value) { topLeft = Coord(value); }},
                                                                                    {"bottom_right", [this](const std::string& value) { bottomRight = Coord(value); }},
                                                                                    };

    for (const auto& [option, value] : options)
    {
        auto it = parameterMap.find(option);
        if (it != parameterMap.end())
            it->second(value);
    }
}
