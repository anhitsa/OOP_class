#ifndef ELIPSEBUILDER_H
#define ELIPSEBUILDER_H

#include "itembuilder.h"
#include "../items/elipse.h"

class ElipseBuilder : public ItemBuilder
{
public:
    ElipseBuilder() : elipse(std::make_unique<Elipse>()) {}
    void addTopLeftCoord(const Coord) override;
    void addBottomRightCoord(const std::optional<Coord>) override;
    void addHeight(const std::optional<Item::Length>) override;
    void addWidth(const std::optional<Item::Length>) override;
    void addID(const int) override;
    std::unique_ptr<Item> getResult() override;

private:
    std::unique_ptr<Elipse> elipse;
};

#endif // ELIPSEBUILDER_H
