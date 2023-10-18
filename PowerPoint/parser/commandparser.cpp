#include "commandparser.h"

#include <optional>
#include "../commands/addcommand.h"

std::unique_ptr<Command> CommandParser::parse(const QString& input)
{
    Tokens tokens = lexer.tokenizeInput(input);

    std::string command_name = determineCommandName(tokens);
    options["item"] = determineValue(tokens, "--item");
    options["top_left"] = determineValue(tokens, "--top_left");
    options["bottom_right"] = determineValue(tokens, "--bottom_right");
    options["height"] = determineValue(tokens, "--height");
    options["width"] = determineValue(tokens, "--width");
    options["id"] = determineValue(tokens, "--id");

    std::unique_ptr<CommandBuilder> command_builder = command_builder_factory.createCommandBuilder(command_name);
    return command_director.construct(std::move(command_builder), options);
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
