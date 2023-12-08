#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "../commands/addcommand.h"
#include "../commands/changecommand.h"
#include "../commands/command.h"
#include "../commands/displaycommand.h"
#include "../commands/exitcommand.h"
#include "../commands/removecommand.h"
#include "../commands/savecommand.h"
#include "../document/coord.h"
#include "../document/container.h"
#include "../document/item.h"
#include "../document/target.h"

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

class CommandFactory
{
public:
    CommandFactory();
    std::unique_ptr<Command> createCommand(std::string command_name);

private:
    std::map<std::string, std::function<std::unique_ptr<Command>()>> commands;

private:
    std::unique_ptr<Command> createAddCommand(const std::unordered_map<std::string, std::string>&);
    std::unique_ptr<Command> createChangeCommand(const std::unordered_map<std::string, std::string>&);
    std::unique_ptr<Command> createRemoveCommand(const std::unordered_map<std::string, std::string>&);
    std::unique_ptr<Command> createExitCommand(const std::unordered_map<std::string, std::string>&);
    std::unique_ptr<Command> createSaveCommand(const std::unordered_map<std::string, std::string>&);
    std::unique_ptr<Command> createDisplayCommand(const std::unordered_map<std::string, std::string>&);

};

#endif // COMMANDFACTORY_H
