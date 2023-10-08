#ifndef CHANGECOMMANDBUILDER_H
#define CHANGECOMMANDBUILDER_H

#include "../commands/changecommand.h"
#include "../commands/command.h"
#include "commandbuilder.h"

#include <memory>
#include <optional>
#include <string>

class ChangeCommandBuilder : public CommandBuilder
{
public:
    ChangeCommandBuilder() { change_command = std::make_unique<ChangeCommand>(); }
    void addTopLeftCoord(const std::optional<std::string>) override;
    void addBottomRightCoord(const std::optional<std::string>) override;
    void addHeight(const std::optional<std::string>) override;
    void addWidth(const std::optional<std::string>) override;
    void addID(const std::optional<std::string>) override;
    std::unique_ptr<Command> getResult() override;

private:
    std::unique_ptr<ChangeCommand> change_command;
};

#endif // CHANGECOMMANDBUILDER_H
