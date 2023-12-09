#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "command.h"
#include "../document/target.h"
#include "../parser/lexer.h"

#include <memory>
#include <optional>
#include <string>
#include <vector>

class AddCommand: public Command
{
public:
    AddCommand(std::unordered_map<std::string, std::string> options);
    void execute() override;

private:
    std::shared_ptr<Target> createTarget();

private:
    std::unordered_map<std::string, std::string> options;
    std::shared_ptr<Target> target;
    std::shared_ptr<Container> container;
    static int slideIdCount;
    static int itemIdCount;

};

#endif // ADDCOMMAND_H
