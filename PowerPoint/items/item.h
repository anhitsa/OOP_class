#ifndef ITEM_H
#define ITEM_H

#include <string>

class ApplicationWindow;

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
    Item();
    Item(Coord top_left, Coord bottom_right);
    Item(Coord top_left, Length height, Length width);
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const { return this->id == other.id; }
    virtual void draw() {}

public:
    Coord top_left, bottom_right;
    Length width, height;
    ID id;

protected:
    ApplicationWindow& appWindow;

};

#endif // ITEM_H
