#ifndef ITEM_H
#define ITEM_H

#include "coord.h"
#include "target.h"

#include <string>

class Item : public Target
{
public:
    using Length = int;

public:
    Item(std::string kind, Coord top_left, Length height, Length width, int id);
    Item(std::string kind, Coord top_left, Coord bottom_right, int id);
    Item(std::string kind, Coord top_left, Coord bottom_right, Length height, Length width, int id);
    void changeParameters(std::unordered_map<std::string, std::string> options) override;
    void undoParametersChange() override;
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const { return this->id == other.id; }

    void setKind(const std::string&);
    const std::string& getKind() const;
    void setTopLeft(const Coord&);
    const Coord& getTopLeft() const;
    void setBottomRight(const Coord&);
    const Coord& getBottomRight() const;
    void setHeight(Length);
    Length getHeight() const;
    void setWidth(Length);
    Length getWidth() const;
    void setId(int);
    int getId() const;

private:
    std::string kind;
    Coord top_left, bottom_right;
    Length height, width;
    int id;

    std::unordered_map<std::string, std::variant<Coord, Length>> prevParameters;

private:
    void saveParameters();

};

#endif // ITEM_H
