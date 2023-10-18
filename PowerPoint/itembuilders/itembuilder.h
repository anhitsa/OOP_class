#ifndef ITEMBUILDER_H
#define ITEMBUILDER_H

#include "../items/coord.h"
#include "../items/item.h"

#include <memory>
#include <optional>
#include <string>

class ItemBuilder
{
public:
    virtual void addTopLeftCoord(const Coord) {}
    virtual void addBottomRightCoord(const std::optional<Coord>) {}
    virtual void addHeight(const std::optional<Item::Length>) {}
    virtual void addWidth(const std::optional<Item::Length>) {}
    virtual void addID(const int) {}
    virtual std::unique_ptr<Item> getResult() = 0;
    virtual ~ItemBuilder() = default;
};

#endif // ITEMBUILDER_H

