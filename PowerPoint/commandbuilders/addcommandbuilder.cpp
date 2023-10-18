#include "addcommandbuilder.h"

void AddCommandBuilder::addItemName(std::optional<std::string> item_name)
{
    if (item_name.has_value())
        add_command->item_name = item_name.value();
    else
        throw std::invalid_argument("No item name provided.");
}

void AddCommandBuilder::addTopLeftCoord(const std::optional<std::string> top_left)
{
    if(top_left.has_value())
        add_command->top_left = Coord(top_left.value());
}

void AddCommandBuilder::addBottomRightCoord(const std::optional<std::string> bottom_right)
{
    if(bottom_right.has_value())
        add_command->bottom_right = Coord(bottom_right.value());
}

void AddCommandBuilder::addHeight(const std::optional<std::string> height)
{
    if(height.has_value())
        add_command->height = std::stoi(height.value());
}

void AddCommandBuilder::addWidth(const std::optional<std::string> width)
{
    if(width.has_value())
        add_command->width = std::stoi(width.value());

}

std::unique_ptr<Command> AddCommandBuilder::getResult()
{
    return std::move(add_command);
}
