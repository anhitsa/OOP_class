#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "../builders/commanddirector.h"
#include "../commands/command.h"
#include "../factory/commandbuilderfactory.h"
#include "lexer.h"
#include "../input_handler/userinputhandler.h"

#include <memory>
#include <string>
#include <sstream>
#include <vector>

class CommandParser
{
public:
    CommandParser()=default;
    std::unique_ptr<Command> parse(UserInputHandler::InputStream&);

private:
    using Tokens = std::vector<std::string>;

private:
    std::string determineCommandName(const Tokens);
    std::optional<std::string> determineValue(const Tokens, const std::string option);

private:
    Lexer lexer;
    CommandBuilderFactory command_builder_factory;
    CommandDirector command_director;

};

#endif // COMMANDPARSER_H
