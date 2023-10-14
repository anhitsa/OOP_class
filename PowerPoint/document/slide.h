#ifndef SLIDE_H
#define SLIDE_H

#include "../items/item.h"

#include <vector>

class Slide
{
public:
    Slide() {}
    void addItem(Item& item);
    Item& getItemByID(const Item::ID id);

public:
    std::vector<Item> items;
};

#endif // SLIDE_H
