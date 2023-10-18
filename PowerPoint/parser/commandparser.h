#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "../commandbuilders/commanddirector.h"
#include "../commands/command.h"
#include "../factory/commandbuilderfactory.h"
#include "lexer.h"
#include "../validator/validator.h"

#include <map>
#include <memory>
#include <QString>
#include <string>
#include <sstream>
#include <vector>

class CommandParser
{
public:
    CommandParser()=default;
    std::unique_ptr<Command> parse(const QString&);

private:
    using Tokens = std::vector<std::string>;

private:
    std::string determineCommandName(const Tokens);
    std::optional<std::string> determineValue(const Tokens, const std::string option);

private:
    Lexer lexer;
    CommandBuilderFactory command_builder_factory;
    CommandDirector command_director;
    Validator validator;
    std::map<std::string, std::optional<std::string>> options;

};

#endif // COMMANDPARSER_H
