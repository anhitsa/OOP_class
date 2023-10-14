#include "slide.h"

void Slide::addItem(Item& item)
{
    items.push_back(item);
}

Item& Slide::getItemByID(const Item::ID id)
{
    for(auto& item: items)
    {
        if(item.id == id)
            return item;
    }
}
