#ifndef LINEBUILDER_H
#define LINEBUILDER_H

#include "itembuilder.h"
#include "../items/coord.h"
#include "../items/line.h"

class LineBuilder : public ItemBuilder
{
public:
    LineBuilder() : line(std::make_unique<Line>()) {}
    void addTopLeftCoord(const Coord) override;
    void addBottomRightCoord(const std::optional<Coord>) override;
    void addWidth(const std::optional<Item::Length>) override;
    void addID(const int) override;
    std::unique_ptr<Item> getResult() override;

private:
    std::unique_ptr<Line> line;
};

#endif // LINEBUILDER_H
