#ifndef REMOVECOMMANDBUILDER_H
#define REMOVECOMMANDBUILDER_H

#include "commandbuilder.h"
#include "../commands/command.h"
#include "../commands/removecommand.h"

#include <memory>
#include <optional>
#include <string>

class RemoveCommandBuilder : public CommandBuilder
{
public:
    RemoveCommandBuilder() : remove_command(std::make_unique<RemoveCommand>()) {}
    std::unique_ptr<Command> getResult() override;
    void addID(const std::optional<std::string>) override;

private:
    std::unique_ptr<RemoveCommand> remove_command;
};

#endif // REMOVECOMMANDBUILDER_H
