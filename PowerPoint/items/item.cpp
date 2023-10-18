#include "item.h"
#include "../user_interface/application_window.h"

Item::Item() : appWindow(ApplicationWindow::getInstance()) {}

Item::Item(Coord top_left, Coord bottom_right): top_left(top_left), bottom_right(bottom_right), appWindow(ApplicationWindow::getInstance())
{
    height = top_left.y - bottom_right.y;
    width = bottom_right.x - top_left.x;
}

Item::Item(Coord top_left, Length height, Length width): top_left(top_left), height(height), width(width), appWindow(ApplicationWindow::getInstance())
{
    bottom_right = Coord(top_left.x + width, top_left.y - height);
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
