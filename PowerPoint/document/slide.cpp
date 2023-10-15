#include "slide.h"

void Slide::addItem(std::unique_ptr<Item> item)
{
    items.push_back(std::move(item));
}
