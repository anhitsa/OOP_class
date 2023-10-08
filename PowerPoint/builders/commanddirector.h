#ifndef COMMANDDIRECTOR_H
#define COMMANDDIRECTOR_H

#include "../commands/command.h"
#include "commandbuilder.h"
#include "../factory/itemfactory.h"

#include <memory>
#include <optional>

class CommandDirector
{
public:
    CommandDirector()=default;
    std::unique_ptr<Command> construct(std::unique_ptr<CommandBuilder>, std::optional<std::string> item_name,
                                       std::optional<std::string> top_left, std::optional<std::string> bottom_right,
                                       std::optional<std::string> height, std::optional<std::string> width,
                                       std::optional<std::string> id);
private:
    ItemFactory item_factory;
};

#endif // COMMANDDIRECTOR_H
