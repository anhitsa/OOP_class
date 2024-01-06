#include "item.h"

Item::Item(std::string kind, RectangleGeometry rect, ID id, std::string color, std::string text)
    : kind(kind), rect(rect), id(id), color(color), text(text)
{

}

const std::string& Item::getKind() const
{
    return kind;
}

const std::string& Item::getColor() const
{
    return color;
}

const std::string& Item::getText() const
{
    return text;
}

const Item::ID& Item::getId() const
{
    return id;
}

RectangleGeometry& Item::getGeometry()
{
    return rect;
}

void Item::setGeometry(const RectangleGeometry& rect_)
{
    rect = rect_;
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

std::string Item::getInfo() const
{
    return "Item kind: " + kind + "\n" +
                  "Item id: " + std::to_string(id) + "\n" +
                  "Top Left Coordinate: " + std::to_string(rect.getTopLeft().getX()) + ", " + std::to_string(rect.getTopLeft().getY()) + "\n" +
                  "Bottom Right Coordinate: " + std::to_string(rect.getBottomRight().getX()) + ", " + std::to_string(rect.getBottomRight().getY()) + "\n" +
                  "Height: " + std::to_string(rect.getHeight()) + "\n" +
                  "Width: " + std::to_string(rect.getWidth()) + "\n";
}
