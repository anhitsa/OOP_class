#include "itemdirector.h"
#include "../items/item.h"

std::unique_ptr<Item> ItemDirector::construct(std::unique_ptr<ItemBuilder> itemBuilder, Coord top_left, std::optional<Coord> bottom_right,
                                              std::optional<Item::Length> height, std::optional<Item::Length> width, Item::ID id)
{
    itemBuilder->addTopLeftCoord(top_left);
    itemBuilder->addBottomRightCoord(bottom_right);
    itemBuilder->addHeight(height);
    itemBuilder->addWidth(width);
    itemBuilder->addID(id);
    return itemBuilder->getResult();
}
