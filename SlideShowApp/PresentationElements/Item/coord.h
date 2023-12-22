#ifndef COORD_H
#define COORD_H

#include <optional>
#include <string>

class Coord
{
public:
    explicit Coord(std::string x, std::string y);
    explicit Coord(int x, int y);
    explicit Coord(std::string token);
    Coord()=default;
    explicit operator bool() const;
    std::optional<Coord> make_optional() const;
    const int& getX() const;
    const int& getY() const;

private:
    int x, y;
};

#endif // COORD_H
