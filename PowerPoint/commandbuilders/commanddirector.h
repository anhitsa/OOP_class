#ifndef COMMANDDIRECTOR_H
#define COMMANDDIRECTOR_H

#include "../commands/command.h"
#include "commandbuilder.h"
#include "../factory/itembuilderfactory.h"

#include <memory>
#include <optional>

class CommandDirector
{
public:
    CommandDirector()=default;
    std::unique_ptr<Command> construct(std::unique_ptr<CommandBuilder>, std::map<std::string, std::optional<std::string>> options);

};

#endif // COMMANDDIRECTOR_H
