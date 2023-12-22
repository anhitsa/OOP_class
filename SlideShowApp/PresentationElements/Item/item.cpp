#include "item.h"

Item::Item(std::string kind, Rectangle rect, ID id):
    kind(kind), rect(rect), id(id)
{

}

void Item::setKind(const std::string& newKind)
{
    kind = newKind;
}

const std::string& Item::getKind() const
{
    return kind;
}

void Item::setId(const ID& newId)
{
    id = newId;
}

void Item::setGeometry(const Rectangle& rect_)
{
    rect = rect_;
}

const Item::ID& Item::getId() const
{
    return id;
}

Item& Item::operator=(const Item& other)
{
    if (this == &other)
        return *this;

    kind = other.kind;
    rect = other.rect;
    id = other.id;
    return *this;
}

Rectangle Item::getGeometry() const
{
    return rect;
}

std::string Item::getInfo() const
{
    return "Item kind: " + kind + "\n" +
                  "Item id: " + std::to_string(id) + "\n" +
                  "Top Left Coordinate: " + std::to_string(rect.getTopLeft().getX()) + ", " + std::to_string(rect.getTopLeft().getY()) + "\n" +
                  "Bottom Right Coordinate: " + std::to_string(rect.getBottomRight().getX()) + ", " + std::to_string(rect.getBottomRight().getY()) + "\n" +
                  "Height: " + std::to_string(rect.getHeight()) + "\n" +
                  "Width: " + std::to_string(rect.getWidth()) + "\n";
}
