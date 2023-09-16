#include <sstream>
#include <vector>

#include "CommandParser.hpp"

Command CommandParser::parseCommand(std::istream& input_stream) 
{
    std::string input;
    std::getline(input_stream, input); 
    std::vector<std::string> tokens = CommandParser::tokenize(std::istringstream(input));
    std::string operationType = tokens[0];
    std::vector<double> operands = CommandParser::determine_operands(tokens);
    return Command(operationType, operands);
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
    for (size_t i = 1; i < tokens.size(); ++i) 
    {
        try 
        {
            double operand = std::stof(tokens[i]);
            operands.push_back(operand);
        } 
        catch (const std::exception& e) 
        {
            throw std::invalid_argument("Invalid operand: " + tokens[i]);
        }
    }
    return operands;
}