#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>

struct Command 
{
    std::string operationType;     
    std::vector<double> operands;   

    Command(const std::string& operationType, const std::vector<double>& operands)
    : operationType(operationType), operands(operands) {}

};

#endif // COMMAND_HPP
