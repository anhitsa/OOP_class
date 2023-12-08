#include "commandparser.h"
#include "../commands/addcommand.h"

#include <optional>


std::unique_ptr<Command> CommandParser::parse(const QString& input)
{
    Tokens tokens = lexer.tokenizeInput(input);
    std::string command_name = determineCommandName(tokens);

    auto optionStart = std::find_if(tokens.begin(), tokens.end(), [](const auto& token) {
        return token.find("--") == 0;
    });

    if (optionStart != tokens.end())
        extractOptions(optionStart, std::prev(tokens.end()));

    return command_factory.createCommand(command_name, options);
}

void CommandParser::extractOptions(Tokens::iterator start, Tokens::iterator end)
{
    for (auto it = start; it != end; ++it)
    {
        std::string key = it->substr(2);
        options[key] = std::next(it)->substr(2);
    }
}

std::string CommandParser::determineCommandName(const Tokens tokens)
{
    validator.verifyCommandName(tokens[0]);
    return tokens[0];
}

std::optional<std::string> CommandParser::determineValue(const Tokens tokens, const std::string option)
{
    for(size_t i = 0; i < tokens.size(); ++i)
    {
        if(tokens[i] == option)
            return tokens[i + 1];
    }
    return {};
}
