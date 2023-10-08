#ifndef EXITCOMMANDBUILDER_H
#define EXITCOMMANDBUILDER_H

#include "commandbuilder.h"
#include "../commands/command.h"
#include "../commands/exitcommand.h"

#include <memory>
#include <optional>
#include <string>

class ExitCommandBuilder : public CommandBuilder
{
public:
    ExitCommandBuilder() { exit_command = std::make_unique<ExitCommand>(); }
    std::unique_ptr<Command> getResult() override { return std::move(exit_command); }

private:
    std::unique_ptr<ExitCommand> exit_command;
};

#endif // EXITCOMMANDBUILDER_H
