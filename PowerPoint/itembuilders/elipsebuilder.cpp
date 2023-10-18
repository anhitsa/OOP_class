#include "elipsebuilder.h"

void ElipseBuilder::addTopLeftCoord(const Coord top_left)
{
    elipse->top_left = top_left;
}

void ElipseBuilder::addBottomRightCoord(const std::optional<Coord> bottom_right)
{
    if(bottom_right.has_value())
        elipse->bottom_right = bottom_right.value();
}

void ElipseBuilder::addHeight(const std::optional<Item::Length> height)
{
    if(height.has_value())
        elipse->height = height.value();
}

void ElipseBuilder::addWidth(const std::optional<Item::Length> width)
{
    if(width.has_value())
        elipse->width = width.value();
}

void ElipseBuilder::addID(const int id)
{
    elipse->id = id;
}

std::unique_ptr<Item> ElipseBuilder::getResult()
{
    return std::move(elipse);
}
