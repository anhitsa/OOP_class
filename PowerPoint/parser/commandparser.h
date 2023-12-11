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
    //TK: Accept istream instead of string
    std::unique_ptr<Command> parse(const QString&);

private:
    using Tokens = std::vector<std::string>;

private:
    std::string determineCommandName(const Tokens);
    std::optional<std::string> determineValue(const Tokens, const std::string option);
    std::map<std::string, std::string> extractOptions(const Tokens&);

private:
    Lexer lexer;
    //TK: If commands are not belonging to the parser then CommandFactory also should be located outside, it is not part of the parser
    CommandFactory command_factory;
    Validator validator;

};

#endif // COMMANDPARSER_H
