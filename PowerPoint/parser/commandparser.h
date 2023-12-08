#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "../commands/command.h"
#include "../factory/commandfactory.h"
#include "lexer.h"
#include "../document/target.h"
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
    CommandFactory command_factory;
    Validator validator;
    std::unordered_map<std::string, std::string> options;

};

#endif // COMMANDPARSER_H
