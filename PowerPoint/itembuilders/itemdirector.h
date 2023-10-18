#ifndef ITEMDIRECTOR_H
#define ITEMDIRECTOR_H

#include "../items/item.h"
#include "itembuilder.h"

#include <memory>
#include <optional>

class ItemDirector
{
public:
    ItemDirector()=default;
    std::unique_ptr<Item> construct(std::unique_ptr<ItemBuilder>, Coord, std::optional<Coord>,
                                    std::optional<Item::Length>, std::optional<Item::Length>, Item::ID id);
};

#endif // ITEMDIRECTOR_H
