#include "displaycommandbuilder.h"

void DisplayCommandBuilder::addID(const std::optional<std::string> id)
{
    if(id.has_value())
        display_command->item->id = std::stoi(id.value());
}

std::unique_ptr<Command> DisplayCommandBuilder::getResult()
{
    return std::move(display_command);
}
