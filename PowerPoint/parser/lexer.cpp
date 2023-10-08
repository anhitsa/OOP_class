#include "lexer.h"

#include <regex>

std::vector<std::string> Lexer::tokenizeInput(UserInputHandler::InputStream& stream)
{
    std::vector<std::string> tokens;
    std::string token;
    while (stream >> token)
        tokens.push_back(token);
    return tokens;
}

std::vector<std::string> Lexer::tokenize(const std::string& str, const char delim=' ')
{
    std::vector<std::string> tokens;
    std::string::size_type beg = 0;
    for (auto end = 0; (end = str.find(delim, end)) != std::string::npos; ++end)
    {
        tokens.push_back(str.substr(beg, end - beg));
        beg = end + 1;
    }
    tokens.push_back(str.substr(beg));
    return tokens;
}

std::pair<Item::Coord, Item::Coord> Lexer::tokenizeCoordinates(std::vector<std::string> operands)
{
    Item::Coord top_left, bottom_right;
    try
    {
        if(std::stoi(tokenize(operands[0], ',')[0]) < std::stoi(tokenize(operands[1], ',')[0]) && std::stoi(tokenize(operands[0], ',')[1]) > std::stoi(tokenize(operands[1], ',')[1]))
        {
            top_left = Item::Coord(tokenize(operands[0], ',')[0], tokenize(operands[0], ',')[1]);
            bottom_right = Item::Coord(tokenize(operands[1], ',')[0], tokenize(operands[1], ',')[1]);
        }
        else if(std::stoi(tokenize(operands[0], ',')[0]) > std::stoi(tokenize(operands[1], ',')[0]) && std::stoi(tokenize(operands[0], ',')[1]) < std::stoi(tokenize(operands[1], ',')[1]))
        {
            top_left = Item::Coord(tokenize(operands[1], ',')[0], tokenize(operands[1], ',')[1]);
            bottom_right = Item::Coord(tokenize(operands[0], ',')[0], tokenize(operands[0], ',')[1]);
        }

    }
    catch (const std::exception& e)
    {
        throw std::invalid_argument("Invalid operands: " + operands[0] + operands[1] + ". Excpected 2 coordinated in this format: 'x, y'.");
    }
    return std::make_pair(top_left, bottom_right);
}

std::tuple<Item::Coord, Item::Length, Item::Length> Lexer::tokenizeCoordinateAndLengths(std::vector<std::string> operands)
{
    Item::Coord top_left;
    Item::Length width, height;
    auto coordPattern = std::regex("\\d+,\\d+");
    for (auto& operand : operands)
    {
        if(std::regex_match(operand, coordPattern))
        {
            top_left = Item::Coord(tokenize(operand, ',')[0], tokenize(operand, ',')[1]);
            operands.erase(std::remove(operands.begin(), operands.end(), operand), operands.end());
        }
    }
    width = std::stoi(operands[0]) < std::stoi(operands[1]) ? std::stoi(operands[0]) : std::stoi(operands[1]);
    height = std::stoi(operands[0]) > std::stoi(operands[1]) ? std::stoi(operands[0]) : std::stoi(operands[1]);
    return std::make_tuple(top_left, height, width);
}
