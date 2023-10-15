#include "itemfactory.h"

ItemFactory::ItemFactory()
{
    items["circle"] = []()  -> std::unique_ptr<Item> { return std::make_unique<Circle>(); };
    items["elipse"] = []()  -> std::unique_ptr<Item> { return std::make_unique<Elipse>(); };
    items["line"] = []()  -> std::unique_ptr<Item> { return std::make_unique<Line>(); };
    items["rectangle"] = []()  -> std::unique_ptr<Item> { return std::make_unique<Rectangle>(); };
    items["triangle"] = []()  -> std::unique_ptr<Item> { return std::make_unique<Triangle>(); };
}

std::optional<std::unique_ptr<Item>> ItemFactory::createItem(std::optional<std::string> item_name)
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

