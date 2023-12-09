#ifndef ITEM_H
#define ITEM_H

#include "coord.h"
#include "target.h"

#include <string>

class Item : public Target
{
public:
    using Length = int;

public:
    Item(std::string kind, Coord top_left, Length height, Length width, int id);
    Item(std::string kind, Coord top_left, Coord bottom_right, int id);
    Item(std::string kind, Coord top_left, Coord bottom_right, Length height, Length width, int id);
    void changeParameters(std::unordered_map<std::string, std::string> options) override;
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const { return this->id == other.id; }

public:
    std::string kind;
    Coord top_left, bottom_right;
    Length height, width;
    int id;

};

#endif // ITEM_H
