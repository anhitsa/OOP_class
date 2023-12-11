#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "command.h"
#include "../document/target.h"
#include "../document/container.h"
#include "../parser/lexer.h"

#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

class AddCommand: public Command
{
public:
    AddCommand(std::map<std::string, std::string> options);
    void execute() override;

private:
    std::shared_ptr<Target> createTarget();
    std::shared_ptr<Container> createContainer(const std::shared_ptr<Target>&);
    std::shared_ptr<Target> createItem();

private:
    std::map<std::string, std::string> options; //TK: duplication
    std::shared_ptr<Target> target;
    std::shared_ptr<Container> container;
    static int slideIdCount;
    static int itemIdCount;

};

#endif // ADDCOMMAND_H
