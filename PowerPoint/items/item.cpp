#include "item.h"
#include "../parser/commandparser.h"

Item::Item(Coord top_left, Coord bottom_right): top_left(top_left), bottom_right(bottom_right)
{
    height = top_left.y - bottom_right.y;
    width = bottom_right.x - top_left.x;
}

Item::Item(Coord top_left, Length height, Length width): top_left(top_left), height(height), width(width)
{
    bottom_right = Coord(top_left.x + width, top_left.y - height);
}

void Item::setID(const ID id_)
{
    id = id_;
}

Item& Item::operator=(const Item& other) {
    if (this == &other)
        return *this;

    top_left = other.top_left;
    bottom_right = other.bottom_right;
    width = other.width;
    height = other.height;
    id = other.id;

    return *this;
}

Item::Coord::Coord(std::string token)
{
    size_t commaPos = token.find(',');

    if (commaPos != std::string::npos)
    {
        x = std::stoi(token.substr(0, commaPos));
        y = std::stoi(token.substr(commaPos + 1));
    }
    else
        throw std::invalid_argument("Coordinate given in a wrong form.");
}
