#include "rectanglebuilder.h"

void RectangleBuilder::addTopLeftCoord(const Coord top_left)
{
    rectangle->top_left = top_left;
}

void RectangleBuilder::addBottomRightCoord(const std::optional<Coord> bottom_right)
{
    if(bottom_right.has_value())
        rectangle->bottom_right = bottom_right.value();
}

void RectangleBuilder::addHeight(const std::optional<Item::Length> height)
{
    if(height.has_value())
        rectangle->height = height.value();
}

void RectangleBuilder::addWidth(const std::optional<Item::Length> width)
{
    if(width.has_value())
        rectangle->width = width.value();
}

void RectangleBuilder::addID(const int id)
{
    rectangle->id = id;
}

std::unique_ptr<Item> RectangleBuilder::getResult()
{
    return std::move(rectangle);
}
