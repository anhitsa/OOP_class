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
