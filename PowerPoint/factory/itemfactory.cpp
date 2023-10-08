#include "itemfactory.h"

ItemFactory::ItemFactory()
{
    items["circle"] = []() { return Circle(); };
    items["elipse"] = []() { return Elipse(); };
    items["line"] = []() { return Line(); };
    items["rectangle"] = []() { return Rectangle(); };
    items["triangle"] = []() { return Triangle(); };
}

std::optional<Item> ItemFactory::createItem(std::optional<std::string> item_name)
{
    if(item_name.has_value())
    {
        auto it = items.find(item_name.value());
        if (it != items.end())
            return it->second();
        throw std::invalid_argument("Not a valid item type.");
    }
    return {};
}
