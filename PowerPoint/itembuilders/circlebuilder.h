#ifndef CIRCLEBUILDER_H
#define CIRCLEBUILDER_H

#include "itembuilder.h"
#include "../items/circle.h"
#include "../items/coord.h"

#include <string>

class CircleBuilder : public ItemBuilder
{
public:
    CircleBuilder() : circle(std::make_unique<Circle>()) {}
    void addTopLeftCoord(const Coord) override;
    void addBottomRightCoord(const std::optional<Coord>) override;
    void addHeight(const std::optional<Item::Length>) override;
    void addWidth(const std::optional<Item::Length>) override;
    void addID(const int) override;
    std::unique_ptr<Item> getResult() override;

private:
    std::unique_ptr<Circle> circle;
};

#endif // CIRCLEBUILDER_H
