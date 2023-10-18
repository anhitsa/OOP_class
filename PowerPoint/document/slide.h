#ifndef SLIDE_H
#define SLIDE_H

#include "../items/item.h"
#include "../user_interface/application_window.h"

#include <vector>

class Slide
{
public:
    Slide()=default;
    void addItem(std::unique_ptr<Item> item);
    void update();

public:
    std::vector<std::unique_ptr<Item>> items;
};

#endif // SLIDE_H
