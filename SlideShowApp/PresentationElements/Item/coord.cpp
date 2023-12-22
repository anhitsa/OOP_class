#include "coord.h"

Coord::Coord(std::string token)
{
    size_t commaPos = token.find(',');

    if (commaPos != std::string::npos)
    {
        x = std::stoi(token.substr(0, commaPos));
        y = std::stoi(token.substr(commaPos + 1));
    }
    else
        throw std::invalid_argument("Coordinate given in a wrong form.");
}

Coord::Coord(std::string x, std::string y) : x(std::stoi(x)), y(std::stoi(y))
{

}

Coord::Coord(int x, int y) : x(x), y(y)
{

}

Coord::operator bool() const
{
    return x && y;
}

std::optional<Coord> Coord::make_optional() const
{
    if (*this)
        return std::optional<Coord>(*this);
    else
        return std::nullopt;
}

const int& Coord::getX() const
{
    return x;
}

const int& Coord::getY() const
{
    return y;
}
