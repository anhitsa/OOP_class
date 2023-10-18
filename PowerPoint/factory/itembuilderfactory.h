#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "../itembuilders/itembuilder.h"
#include "../itembuilders/circlebuilder.h"
#include "../itembuilders/elipsebuilder.h"
#include "../itembuilders/linebuilder.h"
#include "../itembuilders/rectanglebuilder.h"
#include "../itembuilders/trianglebuilder.h"

#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>


class ItemBuilderFactory
{
public:
    ItemBuilderFactory();
    std::unique_ptr<ItemBuilder> createItemBuilder(std::string item_name);

private:
    std::map<std::string, std::function<std::unique_ptr<ItemBuilder>()>> itemsBuilders;
};

#endif // ITEMFACTORY_H
