#include "addcommandbuilder.h"

void AddCommandBuilder::addItem(const std::optional<Item> item)
{
    if(item.has_value())
        add_command->item = item.value();
        return;
    throw std::invalid_argument("No item name provided.");
}

void AddCommandBuilder::addTopLeftCoord(const std::optional<std::string> top_left)
{
    if(top_left.has_value())
        add_command->item.top_left = Item::Coord(top_left.value());
}

void AddCommandBuilder::addBottomRightCoord(const std::optional<std::string> bottom_right)
{
    if(bottom_right.has_value())
        add_command->item.bottom_right = Item::Coord(bottom_right.value());
}

void AddCommandBuilder::addHeight(const std::optional<std::string> height)
{
    if(height.has_value())
        add_command->item.height = std::stoi(height.value());
}

void AddCommandBuilder::addWidth(const std::optional<std::string> width)
{
    if(width.has_value())
        add_command->item.width = std::stoi(width.value());
}

std::unique_ptr<Command> AddCommandBuilder::getResult()
{
    return std::move(add_command);
}
