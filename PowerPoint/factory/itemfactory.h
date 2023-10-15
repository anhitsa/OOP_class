#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "../items/item.h"
#include "../items/circle.h"
#include "../items/elipse.h"
#include "../items/line.h"
#include "../items/rectangle.h"
#include "../items/triangle.h"

#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>


class ItemFactory
{
public:
    ItemFactory();
    std::optional<std::unique_ptr<Item>> createItem(std::optional<std::string> item_name);

private:
    std::map<std::string, std::function<std::unique_ptr<Item>()>> items;
};

#endif // ITEMFACTORY_H
