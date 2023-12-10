#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "../commands/addcommand.h"
#include "../commands/changecommand.h"
#include "../commands/command.h"
#include "../commands/displaycommand.h"
#include "../commands/drawcommand.h"
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
    std::unique_ptr<Command> createCommand(const std::string, std::map<std::string, std::string>);

private:
    std::map<std::string, std::function<std::unique_ptr<Command>(const std::map<std::string, std::string>&)>> commands;


};

#endif // COMMANDFACTORY_H
