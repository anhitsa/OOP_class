#include <sstream>
#include <vector>

#include "CommandParser.hpp"

Command CommandParser::parse_command(std::istream& input_stream) 
{
    Command command;
    std::string input;
    std::getline(input_stream, input); 
    std::vector<std::string> tokens = CommandParser::tokenize(std::istringstream(input));
    if(tokens[0] == "create")
        command.save_in_history =  true;
    command.operation_type = (command.save_in_history) ? tokens[1] : tokens[0];
    command.operands = CommandParser::determine_operands(tokens);
    return command;
}


CommandParser::Tokens CommandParser::tokenize(std::istringstream iss)
{
    Tokens tokens;
    std::string token;
    while (iss >> token) 
    {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<double> CommandParser::determine_operands(const CommandParser::Tokens tokens)
{
    std::vector<double> operands;
    size_t first_idx = (tokens[0] == "create") ? 2 : 1;
    for (size_t i = first_idx; i < tokens.size(); ++i) 
    {
        try 
        {
            double operand = std::stod(tokens[i]);
            operands.push_back(operand);
        } 
        catch (const std::exception& e) 
        {
            throw std::invalid_argument("Invalid operand: " + tokens[i]);
        }
    }
    return operands;
}