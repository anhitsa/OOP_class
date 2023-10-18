#include "removecommandbuilder.h"

void RemoveCommandBuilder::addID(const std::optional<std::string> id)
{
    if(id.has_value())
        remove_command->id = std::stoi(id.value());
}

std::unique_ptr<Command> RemoveCommandBuilder::getResult(){
    return std::move(remove_command);
}

