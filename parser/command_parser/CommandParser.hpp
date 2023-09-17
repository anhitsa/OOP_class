#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <string>
#include <vector>

#include "../commands/Command.hpp"

class CommandParser 
{
    public:
        static Command parse_command(std::istream& input_stream);

    private:
        using Tokens = std::vector<std::string>;
        static Tokens tokenize(std::istringstream);
        static std::vector<double> determine_operands(const Tokens);
};

#endif // COMMAND_PARSER_HPP