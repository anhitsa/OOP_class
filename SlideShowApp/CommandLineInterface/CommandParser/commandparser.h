#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "../Commands/command.h"
#include "../CommandFactory/commandfactory.h"
#include "lexer.h"
#include "../../PresentationElements/document.h"

#include <optional>
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
    std::unique_ptr<Command> parse(std::istream&);

private:
    using Tokens = std::vector<std::string>;

private:
    std::optional<std::string> determineValue(const Tokens, const std::string option);
    std::map<std::string, std::string> extractOptions(const Tokens&);

private:
    Lexer lexer;

};

#endif // COMMANDPARSER_H
