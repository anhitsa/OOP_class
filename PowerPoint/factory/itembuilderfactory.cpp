#include "itembuilderfactory.h"

ItemBuilderFactory::ItemBuilderFactory()
{
    itemsBuilders["circle"] = []()  -> std::unique_ptr<ItemBuilder> { return std::make_unique<CircleBuilder>(); };
    itemsBuilders["elipse"] = []()  -> std::unique_ptr<ItemBuilder> { return std::make_unique<ElipseBuilder>(); };
    itemsBuilders["line"] = []()  -> std::unique_ptr<ItemBuilder> { return std::make_unique<LineBuilder>(); };
    itemsBuilders["rectangle"] = []()  -> std::unique_ptr<ItemBuilder> { return std::make_unique<RectangleBuilder>(); };
    //itemsBuilders["triangle"] = []()  -> std::unique_ptr<ItemBuilder> { return std::make_unique<TriangleBuilder>(); };
}

std::unique_ptr<ItemBuilder> ItemBuilderFactory::createItemBuilder(std::string item_name)
{
    auto it = itemsBuilders.find(item_name);
    if (it != itemsBuilders.end())
        return it->second();
    throw std::invalid_argument("Not a valid item builder type.");

}
