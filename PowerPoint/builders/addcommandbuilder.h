#ifndef ADDCOMMANDBUILDER_H
#define ADDCOMMANDBUILDER_H

#include "../commands/addcommand.h"
#include "../commands/command.h"
#include "commandbuilder.h"

#include <memory>

class AddCommandBuilder : public CommandBuilder
{
public:
    AddCommandBuilder() { add_command = std::make_unique<AddCommand>(); }
    void addItem(const std::optional<std::unique_ptr<Item>>) override;
    void addTopLeftCoord(const std::optional<std::string>) override;
    void addBottomRightCoord(const std::optional<std::string>) override;
    void addHeight(const std::optional<std::string>) override;
    void addWidth(const std::optional<std::string>) override;
    std::unique_ptr<Command> getResult() override;

private:
    std::unique_ptr<AddCommand> add_command;
};

#endif // ADDCOMMANDBUILDER_H
