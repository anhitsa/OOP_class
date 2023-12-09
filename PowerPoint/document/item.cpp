#include "item.h"
#include "../user_interface/application_window.h"

Item::Item(std::string kind, Coord top_left, Length height, Length width, ID id):
    kind(kind), top_left(top_left), height(height), width(width),
    id(id)
{
    bottom_right = Coord(top_left.x + width, top_left.y - height);
}

Item::Item(std::string kind, Coord top_left, Coord bottom_right, ID id):
    kind(kind), top_left(top_left), bottom_right(bottom_right),
    id(id)
{
    height = top_left.y - bottom_right.y;
    width = bottom_right.x - top_left.x;
}

Item::Item(std::string kind, Coord top_left, Coord bottom_right, Length height, Length width, ID id):
    kind(kind), top_left(top_left), bottom_right(bottom_right),
    height(height), width(width), id(id) {}

void Item::changeParameters(std::unordered_map<std::string, std::string> options)
{
    std::unordered_map<std::string, std::function<void(const std::string&)>> parameterMap = {
        {"height", [this](const std::string& value) { height = std::stoi(value); }},
        {"width", [this](const std::string& value) { width = std::stoi(value); }},
        {"top_left", [this](const std::string& value) { top_left = Coord(value); }},
        {"bottom_right", [this](const std::string& value) { bottom_right = Coord(value); }},
    };

    for (const auto& [option, value] : options)
    {
        auto it = parameterMap.find(option);
        if (it != parameterMap.end())
            it->second(value);
    }
}

Item& Item::operator=(const Item& other) {
    if (this == &other)
        return *this;

    kind = other.kind;
    top_left = other.top_left;
    bottom_right = other.bottom_right;
    width = other.width;
    height = other.height;
    id = other.id;

    return *this;
}
