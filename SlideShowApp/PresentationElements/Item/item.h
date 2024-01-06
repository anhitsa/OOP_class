#ifndef ITEM_H
#define ITEM_H

#include "rectanglegeometry.h"

#include <string>

class Item
{
public:
    using ID = int;
    Item(std::string kind, RectangleGeometry rect, ID id, std::string color = "black", std::string text = "");
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const { return this->id == other.id; }

    void setGeometry(const RectangleGeometry&);
    std::string getInfo() const;
    const std::string& getKind() const;
    RectangleGeometry& getGeometry();
    const ID& getId() const;
    const std::string& getColor() const;
    const std::string& getText() const;

private:
    std::string kind;
    std::string color;
    std::string text;
    RectangleGeometry rect;
    ID id;

};

#endif // ITEM_H
