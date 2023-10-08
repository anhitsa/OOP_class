#include "changecommandbuilder.h"

void ChangeCommandBuilder::addTopLeftCoord(const std::optional<std::string> top_left)
{
    if(top_left.has_value())
        change_command->item.top_left = Item::Coord(top_left.value());
}

void ChangeCommandBuilder::addBottomRightCoord(const std::optional<std::string> bottom_right)
{
    if(bottom_right.has_value())
        change_command->item.bottom_right = Item::Coord(bottom_right.value());
}

void ChangeCommandBuilder::addHeight(const std::optional<std::string> height)
{
    if(height.has_value())
        change_command->item.height = std::stoi(height.value());
}

void ChangeCommandBuilder::addWidth(const std::optional<std::string> width)
{
    if(width.has_value())
        change_command->item.width = std::stoi(width.value());
}

void ChangeCommandBuilder::addID(const std::optional<std::string> id)
{
    if(id.has_value())
        change_command->item.id = std::stoi(id.value());
}

std::unique_ptr<Command> ChangeCommandBuilder::getResult()
{
    return std::move(change_command);
}
