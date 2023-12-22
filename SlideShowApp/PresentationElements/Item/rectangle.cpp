#include "rectangle.h"

Rectangle::Rectangle(Coord topLeft, int height, int width)
    : topLeft(topLeft), height(height), width(width)
{
    bottomRight = Coord(topLeft.getX() + width, topLeft.getY() - height);
}

Rectangle::Rectangle(Coord topLeft, Coord bottomRight)
    : topLeft(topLeft), bottomRight(bottomRight)
{
    height = topLeft.getY() - bottomRight.getY();
    width = bottomRight.getX() - topLeft.getX();
}

Rectangle::Rectangle(Coord topLeft, Coord bottomRight, int height, int width)
    : topLeft(topLeft), bottomRight(bottomRight), height(height), width(width)
{

}

Coord Rectangle::getTopLeft() const
{
    return topLeft;
}

Coord Rectangle::getBottomRight() const
{
    return bottomRight;
}

int Rectangle::getHeight() const
{
    return height;
}

int Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setTopLeft(Coord newTopLeft)
{
    topLeft = newTopLeft;
}

void Rectangle::setBottomRight(Coord newBottomRight)
{
    bottomRight = newBottomRight;
}

void Rectangle::setHeight(int newHeight)
{
    height = newHeight;
}

void Rectangle::setWidth(int newWidth)
{
    width = newWidth;
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this == &other)
        return *this;

    topLeft = other.topLeft;
    bottomRight = other.bottomRight;
    width = other.width;
    height = other.height;
    return *this;
}

void Rectangle::revertToLatestParameters()
{
    topLeft = std::get<Coord>(prevParameters.find("top_left")->second);
    bottomRight = std::get<Coord>(prevParameters.find("bottom_right")->second);;
    height = std::get<int>(prevParameters.find("height")->second);
    width = std::get<int>(prevParameters.find("width")->second);
}

void Rectangle::saveParametersLatestVersion()
{
    prevParameters["top_left"] = topLeft;
    prevParameters["bottom_right"] = bottomRight;
    prevParameters["height"] = height;
    prevParameters["width"] = width;
}

void Rectangle::changeParameters(std::map<std::string, std::string> options)
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
