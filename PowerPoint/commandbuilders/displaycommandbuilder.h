#ifndef DISPLAYCOMMANDBUILDER_H
#define DISPLAYCOMMANDBUILDER_H

#include "commandbuilder.h"
#include "../commands/command.h"
#include "../commands/displaycommand.h"

#include <memory>
#include <optional>
#include <string>

class DisplayCommandBuilder : public CommandBuilder
{
public:
    DisplayCommandBuilder() : display_command(std::make_unique<DisplayCommand>()) {}
    void addID(const std::optional<std::string>) override;
    std::unique_ptr<Command> getResult() override;

public:
    int id;

private:
    std::unique_ptr<DisplayCommand> display_command;

};

#endif // DISPLAYCOMMANDBUILDER_H
