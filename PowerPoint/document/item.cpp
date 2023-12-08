#include "item.h"
#include "../user_interface/application_window.h"

Item::Item(std::string kind, Coord top_left, Length height, Length width, ID id):
    kind(kind), top_left(top_left), height(height), width(width),
    id(id)
{
    bottom_right = Coord(top_left.x + width, top_left.y - height);
}

Item::Item(std::string kind, Coord top_left, Coord bottom_right, ID id):
    kind(kind), top_left(top_left), bottom_right(bottom_right),
    id(id)
{
    height = top_left.y - bottom_right.y;
    width = bottom_right.x - top_left.x;
}

Item::Item(std::string kind, Coord top_left, Coord bottom_right, Length height, Length width, ID id):
    kind(kind), top_left(top_left), bottom_right(bottom_right),
    height(height), width(width), id(id) {}

Item& Item::operator=(const Item& other) {
    if (this == &other)
        return *this;

    kind = other.kind;
    top_left = other.top_left;
    bottom_right = other.bottom_right;
    width = other.width;
    height = other.height;
    id = other.id;

    return *this;
}
