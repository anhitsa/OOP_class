#ifndef COORD_H
#define COORD_H

#include <optional>
#include <string>

class Coord
{
public:
    explicit Coord(std::string x, std::string y) : x(std::stoi(x)), y(std::stoi(y)) {}
    explicit Coord(int x, int y) : x(x), y(y) {}
    explicit Coord(std::string token);
    Coord()=default;
    explicit operator bool() const;
    std::optional<Coord> make_optional() const;
    //TK: memeber variables should be private
    int x, y;
};

#endif // COORD_H
