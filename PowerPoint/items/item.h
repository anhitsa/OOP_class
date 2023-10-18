#ifndef ITEM_H
#define ITEM_H

#include "coord.h"

#include <string>

class ApplicationWindow;

class Item
{
public:
    using ID = int;
    using Length = int;

public:
    Item();
    Item(Coord top_left, Coord bottom_right);
    Item(Coord top_left, Length height, Length width);
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const { return this->id == other.id; }
    virtual void draw() {}

public:
    Coord top_left, bottom_right;
    Length width, height;
    ID id;

protected:
    ApplicationWindow& appWindow;

};

#endif // ITEM_H
