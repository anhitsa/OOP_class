#ifndef COMMANDBUILDERFACTORY_H
#define COMMANDBUILDERFACTORY_H

#include "../commandbuilders/commandbuilder.h"
#include "../commandbuilders/addcommandbuilder.h"
#include "../commandbuilders/changecommandbuilder.h"
#include "../commandbuilders/displaycommandbuilder.h"
#include "../commandbuilders/exitcommandbuilder.h"
#include "../commandbuilders/removecommandbuilder.h"

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
