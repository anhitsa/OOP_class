#include "commandparser.h"

#include <optional>

std::unique_ptr<Command> CommandParser::parse(UserInputHandler::InputStream& input)
{
    Tokens tokens = lexer.tokenizeInput(input);

    std::string command_name = determineCommandName(tokens);
    std::optional<std::string> item_name = determineValue(tokens, "--item");
    std::optional<std::string> top_left = determineValue(tokens, "--top_left");
    std::optional<std::string> bottom_right = determineValue(tokens, "--bottom_right");
    std::optional<std::string> height = determineValue(tokens, "--height");
    std::optional<std::string> width = determineValue(tokens, "--width");
    std::optional<std::string> id = determineValue(tokens, "--id");

    std::unique_ptr<CommandBuilder> command_builder = command_builder_factory.createCommandBuilder(command_name);
    return command_director.construct(std::move(command_builder), item_name, top_left, bottom_right, height, width, id);
}

std::string CommandParser::determineCommandName(const Tokens tokens)
{
    // TODO: validation
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
