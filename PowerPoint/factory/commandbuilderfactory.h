#ifndef COMMANDBUILDERFACTORY_H
#define COMMANDBUILDERFACTORY_H

#include "../builders/commandbuilder.h"
#include "../builders/addcommandbuilder.h"
#include "../builders/changecommandbuilder.h"
#include "../builders/displaycommandbuilder.h"
#include "../builders/exitcommandbuilder.h"
#include "../builders/removecommandbuilder.h"

#include <functional>
#include <map>
#include <string>
#include <vector>

class CommandBuilderFactory
{
public:
    CommandBuilderFactory();
    std::unique_ptr<CommandBuilder> createCommandBuilder(std::string command_name);

private:
    std::map<std::string, std::function<std::unique_ptr<CommandBuilder>()>> command_builders;

};

#endif // COMMANDBUILDERFACTORY_H
