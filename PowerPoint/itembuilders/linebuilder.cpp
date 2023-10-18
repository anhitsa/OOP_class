#include "linebuilder.h"

void LineBuilder::addTopLeftCoord(const Coord top_left)
{
    line->top_left = top_left;
}

void LineBuilder::addBottomRightCoord(const std::optional<Coord> bottom_right)
{
    if(bottom_right.has_value())
        line->bottom_right = bottom_right.value();
}

void LineBuilder::addWidth(const std::optional<Item::Length> width)
{
    if(width.has_value())
        line->width = width.value();
}

void LineBuilder::addID(const int id)
{
    line->id = id;
}

std::unique_ptr<Item> LineBuilder::getResult()
{
    return std::move(line);
}
