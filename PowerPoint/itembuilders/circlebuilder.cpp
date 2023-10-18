#include "circlebuilder.h"

void CircleBuilder::addTopLeftCoord(const Coord top_left)
{
    circle->top_left = top_left;
}

void CircleBuilder::addBottomRightCoord(const std::optional<Coord> bottom_right)
{
    if(bottom_right.has_value())
       circle->bottom_right = bottom_right.value();
}

void CircleBuilder::addHeight(const std::optional<Item::Length> height)
{
    if(height.has_value())
        circle->height = height.value();
}

void CircleBuilder::addWidth(const std::optional<Item::Length> width)
{
    if(width.has_value())
        circle->width = width.value();
}

void CircleBuilder::addID(const int id)
{
    circle->id = id;
}

std::unique_ptr<Item> CircleBuilder::getResult()
{
    return std::move(circle);
}
