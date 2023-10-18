#include "commandbuilderfactory.h"

#include <iostream>

CommandBuilderFactory::CommandBuilderFactory()
{
    command_builders["add"] = []() -> std::unique_ptr<CommandBuilder> { return std::make_unique<AddCommandBuilder>(); };
    command_builders["change"] = []() -> std::unique_ptr<CommandBuilder> { return std::make_unique<ChangeCommandBuilder>(); };
    command_builders["display"] = []() -> std::unique_ptr<CommandBuilder> { return std::make_unique<DisplayCommandBuilder>(); };
    command_builders["exit"] = []() -> std::unique_ptr<CommandBuilder> { return std::make_unique<ExitCommandBuilder>(); };
    command_builders["remove"] = []() -> std::unique_ptr<CommandBuilder> { return std::make_unique<RemoveCommandBuilder>(); };
}

std::unique_ptr<CommandBuilder> CommandBuilderFactory::createCommandBuilder(const std::string command_name)
{
    auto it = command_builders.find(command_name);
    if (it != command_builders.end())
        return it->second();
    throw std::invalid_argument("Not a valid command name");
}
