#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <utility> // std::make_pair

class Item
{
public:
    using ID = int;
    using Length = int;
    struct Coord
    {
        explicit Coord(std::string x, std::string y) : x(std::stoi(x)), y(std::stoi(y)) { }
        explicit Coord(int x, int y) : x(x), y(y) {}
        explicit Coord(std::string token);
        Coord()=default;
        int x, y;
    };

public:
    Item()=default;
    Item(Coord top_left, Coord bottom_right);
    Item(Coord top_left, Length height, Length width);
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const {
        return this->id == other.id;
    }
    void setID(const ID);

public:
    Coord top_left, bottom_right;
    Length width, height;
    ID id;
};

#endif // ITEM_H
