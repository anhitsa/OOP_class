#ifndef RECTANGLEBUILDER_H
#define RECTANGLEBUILDER_H

#include "itembuilder.h"
#include "../items/rectangle.h"

#include <string>

class RectangleBuilder : public ItemBuilder
{
public:
    RectangleBuilder() : rectangle(std::make_unique<Rectangle>()) {}
    void addTopLeftCoord(const Coord) override;
    void addBottomRightCoord(const std::optional<Coord>) override;
    void addHeight(const std::optional<Item::Length>) override;
    void addWidth(const std::optional<Item::Length>) override;
    void addID(const int) override;
    std::unique_ptr<Item> getResult() override;

private:
    std::unique_ptr<Rectangle> rectangle;
};

#endif // RECTANGLEBUILDER_H
