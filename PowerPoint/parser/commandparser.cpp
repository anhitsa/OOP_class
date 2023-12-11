#include "commandparser.h"
#include "../commands/addcommand.h"

#include <optional>


std::unique_ptr<Command> CommandParser::parse(const QString& input)
{
    Tokens tokens = lexer.tokenizeInput(input);
    std::string command_name = determineCommandName(tokens);
    std::map<std::string, std::string> options = extractOptions(tokens);
    return command_factory.createCommand(command_name, options);
}

std::map<std::string, std::string> CommandParser::extractOptions(const Tokens& tokens)
{
    //TK: options extraction could be organized more simple and safe way
    auto start = std::find_if(tokens.begin(), tokens.end(), [](const auto& token) {
        return token.find("--") == 0;
    });

    std::map<std::string, std::string> options;
    for (auto it = start; std::distance(it, tokens.end()) >= 2; it += 2)
    {
        std::string key = it->substr(2);
        options[key] = *(std::next(it));
    }
    return options;
}

std::string CommandParser::determineCommandName(const Tokens tokens)
{
    //TK: Determination of the command is simply lookup of the command in the command factory
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
