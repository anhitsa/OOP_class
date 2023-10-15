#ifndef SLIDE_H
#define SLIDE_H

#include "../items/item.h"

#include <vector>

class Slide
{
public:
    Slide() {}
    void addItem(std::unique_ptr<Item> item);

public:
    std::vector<std::unique_ptr<Item>> items;
};

#endif // SLIDE_H
