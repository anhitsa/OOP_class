#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "command.h"
#include "../parser/lexer.h"

#include <memory>
#include <optional>
#include <string>
#include <vector>

class AddCommand: public Command
{
public:
    AddCommand()=default;
    AddCommand(std::shared_ptr<Target>);
    void execute() override;

public:
    static int slideIdCount;
    static int itemIdCount;

private:
    std::shared_ptr<Target> target;
    std::shared_ptr<Container> container;

};

#endif // ADDCOMMAND_H
